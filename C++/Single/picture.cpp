#include<iostream>
using namespace std;
#define maxsize 20
typedef struct ArcNode{
    int adjvex;
    int info;
    ArcNode *nextarc;
 }ArcNode;
typedef struct{
   char data;
  ArcNode *firstarc;
}Vexnode;
class graph{
private: 
     Vexnode adj[maxsize];
     int e,n;
public:
    void  create(int n,int e);//����n�����㣬e���ߵ�ͼ
    int searchX(char x);//����ֵΪx�Ķ������ţ�
    int degree(char x);//����ֵΪx�Ľ��Ķ�����
    void addarc(char u,char v,int w);//����һ����
    
};
int graph::searchX(char x){//����ֵΪx�Ķ�������
     for(int i=0;i<n;i++)
        if(adj[i].data==x) return i;
     return -1;
}
void  graph::create(int m,int k){//����m�����㣬k���ߵ�ͼ
    int h,t,w;    char u,v;
	ArcNode *p;
   for(int i=0;i<m;i++) {//���붥�㼯
      cin>> adj[i].data;  
      adj[i].firstarc=NULL;
   }
   n=m;e=k;

  for(int j=0;j<k;j++){//����߼�
      cin>>u>>v>>w;//����һ����<u,v,w>
      h=searchX(u);
      t=searchX(v);
      p =new ArcNode;
      p->adjvex=t;
      p->info=w;
      p->nextarc=adj[h].firstarc;
      adj[h].firstarc=p;
     }
}
int graph::degree(char x){//����ֵΪx�Ľ��Ķ���
     int t=searchX(x);                      
    ArcNode *p=adj[t].firstarc;
    int count=0;
    while(p){
        count++;
        p=p->nextarc;
     }
    return count;
}
void graph::addarc(char u,char v,int w){//����һ����
    int h=searchX(u),t=searchX(v);
    if(h==-1){adj[n].data=u;
                     adj[n].firstarc=NULL;
                     h=n;  n++;
                     }
     if(t==-1){adj[n].data=v;
                     adj[n].firstarc=NULL;
                     t=n;  n++;
                    }
      ArcNode *p=new ArcNode;
      p->adjvex=t;   p->info=w;
      p->nextarc=adj[h].firstarc;
      adj[h].firstarc=p;
      e++;
}
int  main(){
    graph g;
    g.create(5,6);
    cout<<g.degree('b')<<endl;
    g.addarc('b','e',10);
    cout<<g.degree('b');
	return 0;
}

