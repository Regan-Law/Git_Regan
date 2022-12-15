#include<iostream>
using namespace std;
#define MaxSize 100
typedef struct CtNode{
     int child;                     //���ӽ���������е��±�
    CtNode *next;                //ָ����һ�����ӽ��
}CtNode;
typedef struct{
    char data;           //���н�㱾���������Ϣ��Ϊ�˼򵥶���Ϊ�ַ���
    int parent;           //����Ǵ�˫�׺��������ʾ������˫����Ϣ
    CtNode *firstchild;              //ָ���һ�����ӽ��
}CtBox;
class CTree{
  private:
    CtBox nodes[MaxSize];
    int r,n;                      //����λ�ú����Ľ����
  public:
    int LocateNode(char x);        //���ҽ��x�����е��±�
    void CreateCtree(int k);        //����k��������
    int DegreeNode(char x);        //������x�Ķ���
    void InsertNode(char u,char v);  //������u�ĺ���v
};
int CTree::LocateNode(char x){//���ҽ��x�����ҵ��������±꣬���򷵻�-1
    for(int i=0;i<n;i++)
      if(x==nodes[i].data)return i;
    return -1;
}
void CTree::CreateCtree(int k){
    int i;
    for(i=0;i<k;i++){             //�������д�����н����Ϣ
      cin>>nodes[i].data;
      nodes[i].firstchild=NULL;
    }
    n=k;r=0;
    char u,v;
    int h,t;
    CtNode *p;
    for(i=0;i<k;i++){            //�������н��ĺ��ӽ��
      cin>>u;                  //��������
      h=LocateNode(u);
      cin>>v;                  //���뺢�ӽ��
      while(v!='.'){             //����u�����к��ӽ��
         t=LocateNode(v);
         p=new CtNode;         //ͷ���뷨���Ӻ��ӽ��
         p->child=t;
         p->next=nodes[h].firstchild;
         nodes[h].firstchild=p;
         cin>>v;
      }
    }
}
int CTree::DegreeNode(char x){ //������x�Ķ���
   int h=LocateNode(x);
   CtNode *p=nodes[h].firstchild;
   int count=0;
   while(p){                     //�������ӽ��
       count++;
       p=p->next;
   }
   return count;
}
void CTree::InsertNode(char u,char v){//������u�ĺ���v
    int h=LocateNode(u);
    if(h==-1) return;              //u���������޷�������v
    nodes[n].data=v;              //v����˳�����
    nodes[n].firstchild=NULL;
    n++;
    CtNode *p=new CtNode;      //ͷ�巨������v
    int t=LocateNode(v);
    p->child=t;
    p->next=nodes[h].firstchild;
    nodes[h].firstchild=p;
}
int main( ){
      CTree ct;                      //˵��һ������
      ct. CreateCtree(4);              //����ͼ10��������
      cout<<ct.DegreeNode('D')<<endl;  //������D�Ķ���
      ct. InsertNode('D','M');          //���D���뺢��M
      cout<< ct.DegreeNode('D')<<endl; //������D�Ķ���
}
