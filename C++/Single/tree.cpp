#include<iostream>
using namespace std;
#define MaxSize 100
typedef struct CtNode{
     int child;                     //孩子结点在数组中的下标
    CtNode *next;                //指向下一个孩子结点
}CtNode;
typedef struct{
    char data;           //树中结点本身的数据信息，为了简单定义为字符型
    int parent;           //如果是带双亲孩子链表表示，增加双亲信息
    CtNode *firstchild;              //指向第一个孩子结点
}CtBox;
class CTree{
  private:
    CtBox nodes[MaxSize];
    int r,n;                      //根的位置和树的结点数
  public:
    int LocateNode(char x);        //查找结点x在树中的下标
    void CreateCtree(int k);        //创建k个结点的树
    int DegreeNode(char x);        //计算结点x的度数
    void InsertNode(char u,char v);  //插入结点u的孩子v
};
int CTree::LocateNode(char x){//查找结点x，若找到返回其下标，否则返回-1
    for(int i=0;i<n;i++)
      if(x==nodes[i].data)return i;
    return -1;
}
void CTree::CreateCtree(int k){
    int i;
    for(i=0;i<k;i++){             //在数组中存放所有结点信息
      cin>>nodes[i].data;
      nodes[i].firstchild=NULL;
    }
    n=k;r=0;
    char u,v;
    int h,t;
    CtNode *p;
    for(i=0;i<k;i++){            //读入所有结点的孩子结点
      cin>>u;                  //读入根结点
      h=LocateNode(u);
      cin>>v;                  //读入孩子结点
      while(v!='.'){             //连接u的所有孩子结点
         t=LocateNode(v);
         p=new CtNode;         //头插入法连接孩子结点
         p->child=t;
         p->next=nodes[h].firstchild;
         nodes[h].firstchild=p;
         cin>>v;
      }
    }
}
int CTree::DegreeNode(char x){ //计算结点x的度数
   int h=LocateNode(x);
   CtNode *p=nodes[h].firstchild;
   int count=0;
   while(p){                     //遍历孩子结点
       count++;
       p=p->next;
   }
   return count;
}
void CTree::InsertNode(char u,char v){//插入结点u的孩子v
    int h=LocateNode(u);
    if(h==-1) return;              //u不在树中无法插入结点v
    nodes[n].data=v;              //v放入顺序表中
    nodes[n].firstchild=NULL;
    n++;
    CtNode *p=new CtNode;      //头插法插入结点v
    int t=LocateNode(v);
    p->child=t;
    p->next=nodes[h].firstchild;
    nodes[h].firstchild=p;
}
int main( ){
      CTree ct;                      //说明一个对象
      ct. CreateCtree(4);              //创建图10个结点的树
      cout<<ct.DegreeNode('D')<<endl;  //计算结点D的度数
      ct. InsertNode('D','M');          //结点D插入孩子M
      cout<< ct.DegreeNode('D')<<endl; //计算结点D的度数
}
