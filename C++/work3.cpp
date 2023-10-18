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
	int visited; //节点访问状态
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
	void CreateGraph(int n, int m);		 //创建n个顶点，m条边的连通无向图
	int LocateVex(char u);				 //查找值为u的顶点的图
	int Degree(char u);					 //计算值为u的结点的度数
	void Insert(char u, char v, int info); //插入一条边
	void DFS(char v);					 //深度优先搜索
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
	cout << "请输入顶点集：";
	for (int i = 0; i < n; i++) //循环输入顶点集
	{
		cin >> ag.vertices[i].data;
		ag.vertices[i].firstarc = NULL;
	}
	cout << endl;
	cout << "请输入边集：";
	for (int j = 0; j < m; j++) //循环输入边集
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
    cout<<"请输入需要创建图的顶点数v和边数e："<<endl;
	cout<<"v:";
	cin>>v;
	cout<<"e:";
	cin>>e;
	cout<<"请输需要创建图的顶点集和边集：";
    g.CreateGraph(v,e);
    cout<<"深度优先搜索的结果为：";
    g.DFSTraverse();
    cout<<endl;
	system("pause");
    return 0;
}
