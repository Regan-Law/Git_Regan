#include<iostream>
using namespace std;
#define MaxSize 100
typedef struct BiTNode
{
    int data;//数据元素信息
    BiTNode*lt;//指向左孩子节点
    BiTNode*rt;//指向右孩子节点
} BiTNode;
class BiTree
{
private:
    BiTNode*bt;
    void Rcreate(BiTNode*&t);//创建二叉树
    void InTraverse(BiTNode*t);//中序遍历输出二叉树
    int countDepth(BiTNode*t);//计算二叉树的树高
    int countDegreenumber(BiTNode*t,int x);//计算二叉树中节点值大于x的结点数
    int countDegree2(BiTNode*t);//计算二叉树中度为2的结点数
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
    if(ch==-1)//如果值为-1，令指针为空，结束函数 
    {
        t=NULL;
    }
    else//否则插入节点，并递归调用 
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
    if(t==NULL)//如果指针为空，结束函数 
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
    if(t==NULL)//如果指针为空，结束函数 
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

    if(!t||!t->lt&&!t->rt)//t为空或是叶子
    {
        return 0;
    }
    if(t->lt&&t->rt)//t是2度结点
    {
        return 1+countDegree2(t->lt)+countDegree2(t->rt);//递归调用，左右字树都非空时，返回值加一，否则不加
    }
    else//t是1度结点
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
    cout<<"输入二叉树信息（若二叉树的孩子为空，则输入-1）"<<endl;
    a.createBiTree();
    cout<<"中序遍历输出二叉树"<<endl;
    a.InTraverseBiTree();
    cout<<endl;
    cout<<"二叉树的深度为："<<a.Depth()<<endl;
    cout<<"输入x以求二叉树中节点值大于x的结点数"<<endl;
    int x;
    cin>>x;
    cout<<"二叉树中节点值大于x的结点数为："<<a.Degree(x)<<endl;
    cout<<"二叉树中度为2的结点数为："<<a.Degree2()<<endl;
    system("pause");
    return 0;
}