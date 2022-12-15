#include<iostream>
using namespace std;
#define MaxSize 100
typedef struct BiTNode
{
    int data;//����Ԫ����Ϣ
    BiTNode*lt;//ָ�����ӽڵ�
    BiTNode*rt;//ָ���Һ��ӽڵ�
} BiTNode;
class BiTree
{
private:
    BiTNode*bt;
    void Rcreate(BiTNode*&t);//����������
    void InTraverse(BiTNode*t);//����������������
    int countDepth(BiTNode*t);//���������������
    int countDegreenumber(BiTNode*t,int x);//����������нڵ�ֵ����x�Ľ����
    int countDegree2(BiTNode*t);//����������ж�Ϊ2�Ľ����
public:
    BiTree()
    {
        bt=NULL;
    }
    void createBiTree();
    void InTraverseBiTree();
    int Depth();
    int Degree(int x);
    int Degree2();
};

void BiTree::Rcreate(BiTNode*&t)
{
    int ch;
    cin>>ch;
    if(ch==-1)//���ֵΪ-1����ָ��Ϊ�գ��������� 
    {
        t=NULL;
    }
    else//�������ڵ㣬���ݹ���� 
    {
        t=new BiTNode;
        t->data=ch;
        Rcreate(t->lt);
        Rcreate(t->rt);
    }
}
void BiTree::createBiTree()
{
    BiTNode*t;
    Rcreate(t);
    bt=t;
}

void BiTree::InTraverse(BiTNode*t)
{
    if(t)
    {
        InTraverse(t->lt);
        cout<<t->data<<' ';
        InTraverse(t->rt);
    }
}

void BiTree::InTraverseBiTree()
{
    BiTNode*p=bt;
    InTraverse(p);
}

int BiTree::countDepth(BiTNode*t)
{
    if(t==NULL)//���ָ��Ϊ�գ��������� 
    {
        return 0;
    }
    else
    {
        int m=1+countDepth(t->lt);
        int n=1+countDepth(t->rt);
        if(m>=n)
        {
            return m;
        }
        else
        {
            return n;
        }
    }
}
int BiTree::Depth()
{
    BiTNode*p=bt;
    return countDepth(p);
}
int BiTree::countDegreenumber(BiTNode*t,int x)
{
    int n;
    if(t==NULL)//���ָ��Ϊ�գ��������� 
    {
        return 0;
    }
    if(t->data>=x)
    {
        n=1;
    }
    else
    {
        n=0;
    }
    return n+countDegreenumber(t->lt,x)+countDegreenumber(t->rt,x);
}
int BiTree::Degree(int x)
{
    BiTNode*p=bt;
    return countDegreenumber(p,x);
}
int BiTree::countDegree2(BiTNode*t)
{

    if(!t||!t->lt&&!t->rt)//tΪ�ջ���Ҷ��
    {
        return 0;
    }
    if(t->lt&&t->rt)//t��2�Ƚ��
    {
        return 1+countDegree2(t->lt)+countDegree2(t->rt);//�ݹ���ã������������ǿ�ʱ������ֵ��һ�����򲻼�
    }
    else//t��1�Ƚ��
    {
        return countDegree2(t->lt)+countDegree2(t->rt);
    }
}
int BiTree::Degree2()
{
    BiTNode*p=bt;
    return countDegree2(p);
}
int main()
{
    BiTree a;
    cout<<"�����������Ϣ�����������ĺ���Ϊ�գ�������-1��"<<endl;
    a.createBiTree();
    cout<<"����������������"<<endl;
    a.InTraverseBiTree();
    cout<<endl;
    cout<<"�����������Ϊ��"<<a.Depth()<<endl;
    cout<<"����x����������нڵ�ֵ����x�Ľ����"<<endl;
    int x;
    cin>>x;
    cout<<"�������нڵ�ֵ����x�Ľ����Ϊ��"<<a.Degree(x)<<endl;
    cout<<"�������ж�Ϊ2�Ľ����Ϊ��"<<a.Degree2()<<endl;
    system("pause");
    return 0;
}