#include<iostream>
using namespace std;
typedef struct lnode
{
    int coef;//ϵ��
    int exp;//ָ��
    lnode*next;
} lnode;
class poly
{
private:
    lnode*head;

public:
    void create(int n);//����n��Ķ���ʽ
    void mult(poly&ha,poly hb);//����ʽ�ĳ˷��ͺϲ�ͬ����
    void print();//��ӡ���
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
            if(n->next->exp==m->exp&&n->next!=m)//�ϲ�ͬ����
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
            cout<<p->coef<<"x��"<<p->exp<<"�η�+";
        }
        else
        {
            cout<<p->coef<<"x��"<<p->exp<<"�η�";
        }
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    poly ha,hb,hc;
    int n1,n2;
    cout<<"�������һ������ʽ������"<<endl;
    cin>>n1;
    cout<<"�������һ������ʽ"<<endl;
    ha.create(n1);
    cout<<"������ڶ�������ʽ������"<<endl;
    cin>>n2;
    cout<<"������ڶ�������ʽ"<<endl;
    hb.create(n2);
    cout<<"��һ������ʽΪ��";
    ha.print();
    cout<<"�ڶ�������ʽΪ��";
    hb.print();
    cout<<"������ʽ�ĳ˻�Ϊ��";
    ha.mult(ha,hb);
    ha.print();
    system("pause");
    return 0;
}