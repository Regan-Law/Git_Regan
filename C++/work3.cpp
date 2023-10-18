#include <iostream>
using namespace std;
#define MaxVex 20
typedef struct ArcNode
{
	int adjvex;
	int info;
	ArcNode *nextarc;
} ArcNode;
typedef struct
{
	char data;
	int visited; //�ڵ����״̬
	ArcNode *firstarc;
} VNode;
typedef struct
{
	VNode vertices[MaxVex];
	int vexnum;
	int arcnum;
} AdjLGraph;
class ALGraph
{
private:
	AdjLGraph ag;

public:
	void CreateGraph(int n, int m);		 //����n�����㣬m���ߵ���ͨ����ͼ
	int LocateVex(char u);				 //����ֵΪu�Ķ����ͼ
	int Degree(char u);					 //����ֵΪu�Ľ��Ķ���
	void Insert(char u, char v, int info); //����һ����
	void DFS(char v);					 //�����������
	void DFSTraverse();
	AdjLGraph GetAg() { return ag; }
};

void ALGraph::CreateGraph(int n, int m)
{
	ag.vexnum = n;
	ag.arcnum = m;
	int w, h, t;
	char u, v;
	ArcNode *p;
	cout << "�����붥�㼯��";
	for (int i = 0; i < n; i++) //ѭ�����붥�㼯
	{
		cin >> ag.vertices[i].data;
		ag.vertices[i].firstarc = NULL;
	}
	cout << endl;
	cout << "������߼���";
	for (int j = 0; j < m; j++) //ѭ������߼�
	{
		cin >> u >> v >> w;
		h = LocateVex(u);
		t = LocateVex(v);
		p = new ArcNode;
		p->adjvex = t;
		p->info = w;
		p->nextarc = ag.vertices[h].firstarc;
		ag.vertices[h].firstarc = p;
		p = new ArcNode;
		p->adjvex = h;
		p->info = w;
		p->nextarc = ag.vertices[t].firstarc;
		ag.vertices[t].firstarc = p;
	}
}

int ALGraph::LocateVex(char u)
{
	for (int i = 0; i < ag.vexnum; i++)
		if (u == ag.vertices[i].data)
			return i;
	return -1;
}
int ALGraph::Degree(char u)
{
	char h = LocateVex(u);
	int count = 0;
	ArcNode *p = ag.vertices[h].firstarc;
	while (p)
	{
		count++;
		p = p->nextarc;
	}
	return count;
}

void ALGraph::Insert(char u, char v, int info)
{
	char h = LocateVex(u), t = LocateVex(v);
	ArcNode *p;
	if (h == -1)
	{
		ag.vertices[ag.vexnum].data = u;
		ag.vertices[ag.vexnum].firstarc = NULL;
		h = ag.vexnum;
		ag.vexnum++;
	}
	if (t == -1)
	{
		ag.vertices[ag.vexnum].data = v;
		ag.vertices[ag.vexnum].firstarc = NULL;
		t = ag.vexnum;
		ag.vexnum++;
	}
	p = new ArcNode;
	p->adjvex = t;
	p->info = info;
	p->nextarc = ag.vertices[h].firstarc;
	ag.vertices[h].firstarc = p;
	p = new ArcNode;
	p->adjvex = h;
	p->info = info;
	p->nextarc = ag.vertices[t].firstarc;
	ag.vertices[t].firstarc = p;
	ag.arcnum++;
}

void ALGraph::DFS(char v)
{
	ArcNode *p;
	char h = LocateVex(v);
	cout << v;
	ag.vertices[h].visited = 1;
	for (p = ag.vertices[h].firstarc; p; p = p->nextarc)
	{
		if (ag.vertices[p->adjvex].visited == 0)
		{
			DFS(ag.vertices[p->adjvex].data); 
		}
	}
}
void ALGraph::DFSTraverse()
{
	for (int i = 0; i < ag.vexnum; i++)
	{
		ag.vertices[i].visited = 0;
	}
	for (int i = 0; i < ag.vexnum; i++)
	{
		if (!ag.vertices[i].visited)
		{
			DFS(ag.vertices[i].data);
		}
	}
}
int main()
{
	ALGraph g;
    int x,v,e;
    cout<<"��������Ҫ����ͼ�Ķ�����v�ͱ���e��"<<endl;
	cout<<"v:";
	cin>>v;
	cout<<"e:";
	cin>>e;
	cout<<"������Ҫ����ͼ�Ķ��㼯�ͱ߼���";
    g.CreateGraph(v,e);
    cout<<"������������Ľ��Ϊ��";
    g.DFSTraverse();
    cout<<endl;
	system("pause");
    return 0;
}
