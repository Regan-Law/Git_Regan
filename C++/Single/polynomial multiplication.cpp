#include<iostream>
using namespace std;
typedef struct lnode
{
    int coef;//系数
    int exp;//指数
    lnode*next;
} lnode;
class poly
{
private:
    lnode*head;

public:
    void create(int n);//创建n项的多项式
    void mult(poly&ha,poly hb);//多项式的乘法和合并同类项
    void print();//打印结果
};
void poly::create(int n)
{
    head=new lnode;
    head->next=NULL;
    lnode*p;
    for(int i=0;i<n;i++)
    {
        p=new lnode;
        cin>>p->coef>>p->exp;
        p->next=head->next;
        head->next=p;
    }
}

void poly::mult(poly&ha,poly hb)
{
    lnode*q=ha.head,*pa=ha.head->next,*pb=hb.head->next,*r,*t,*m,*n,*temp;
    t=new lnode;
    t->next=NULL;
    while(pa)
    {
        while(pb)
        {
            r=new lnode;
            r->coef=pa->coef*pb->coef;
            r->exp=pa->exp+pb->exp;
            pb=pb->next;
            r->next=t->next;
            t->next=r;
        }
        pb=hb.head->next;
        pa=pa->next;
    }
    q->next=t->next;
    m=q;
    n=q;
    while(m->next)
    {
        m=m->next;
        while(n->next)
        {
            if(n->next->exp==m->exp&&n->next!=m)//合并同类项
            {
                m->coef+=n->next->coef;
                temp=n->next;
                n->next=temp->next;
                delete temp;
            }
            n=n->next;
        }
        n=q;
    }
}
void poly::print()
{
    lnode*p=head->next;
    while(p)
    {
        if(p->next)
        {
            cout<<p->coef<<"x的"<<p->exp<<"次方+";
        }
        else
        {
            cout<<p->coef<<"x的"<<p->exp<<"次方";
        }
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    poly ha,hb,hc;
    int n1,n2;
    cout<<"请输入第一个多项式的项数"<<endl;
    cin>>n1;
    cout<<"请输入第一个多项式"<<endl;
    ha.create(n1);
    cout<<"请输入第二个多项式的项数"<<endl;
    cin>>n2;
    cout<<"请输入第二个多项式"<<endl;
    hb.create(n2);
    cout<<"第一个多项式为：";
    ha.print();
    cout<<"第二个多项式为：";
    hb.print();
    cout<<"两多项式的乘积为：";
    ha.mult(ha,hb);
    ha.print();
    system("pause");
    return 0;
}