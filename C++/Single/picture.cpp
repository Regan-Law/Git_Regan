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
    void  create(int n,int e);//创建n个顶点，e条边的图
    int searchX(char x);//查找值为x的顶点的序号；
    int degree(char x);//计算值为x的结点的度数；
    void addarc(char u,char v,int w);//增加一条边
    
};
int graph::searchX(char x){//查找值为x的顶点的序号
     for(int i=0;i<n;i++)
        if(adj[i].data==x) return i;
     return -1;
}
void  graph::create(int m,int k){//创建m个顶点，k条边的图
    int h,t,w;    char u,v;
	ArcNode *p;
   for(int i=0;i<m;i++) {//输入顶点集
      cin>> adj[i].data;  
      adj[i].firstarc=NULL;
   }
   n=m;e=k;

  for(int j=0;j<k;j++){//输入边集
      cin>>u>>v>>w;//输入一条弧<u,v,w>
      h=searchX(u);
      t=searchX(v);
      p =new ArcNode;
      p->adjvex=t;
      p->info=w;
      p->nextarc=adj[h].firstarc;
      adj[h].firstarc=p;
     }
}
int graph::degree(char x){//计算值为x的结点的度数
     int t=searchX(x);                      
    ArcNode *p=adj[t].firstarc;
    int count=0;
    while(p){
        count++;
        p=p->nextarc;
     }
    return count;
}
void graph::addarc(char u,char v,int w){//增加一条边
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

