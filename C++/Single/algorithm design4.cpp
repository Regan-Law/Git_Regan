#include<iostream>
using namespace std;
typedef struct dnode
{
    dnode*prev;
    int data;
    dnode*next;
} dnode;
class doublelinklist
{
private:
    dnode*head;

public:
    doublelinklist();
    ~doublelinklist();
    void createn(int n);
    void print();
    void deletelist(int min,int max);
};
doublelinklist::doublelinklist()
{
    head=new dnode;
    head->next=head->prev=NULL;
}

void doublelinklist::createn(int n)
{
    dnode*p;
    for(int i=0;i<n;i++)
    {
        p=new dnode;
        cin>>p->data;
        p->next=head->next;
        p->prev=head;
        if(head->next !=NULL)
        {
            head->next->prev=p;
        }
        head->next=p;
    }
}
doublelinklist::~doublelinklist()
{
    dnode*p;
    while(head)
    {
        p=head;
        head=head->next;
        delete p;
    }
    head=NULL;
}
void doublelinklist::print()
{
    dnode*p=head->next;
    while(p)
    {
        cout<<p->data<<' ';
        p=p->next;
    }
    cout<<endl;
}
void doublelinklist::deletelist(int min,int max)
{
    dnode*p=head;
    dnode*mi=p->next;
    while(mi)
    {
        if(mi->data==min)
        {
            dnode*ma=mi->next;
            while(ma)
            {
                if(ma->data==max)
                {
                    dnode*s,*t;
                    s=mi->next;
                    while(s!=ma&&s->data<max)
                    {
                        mi->next=s->next;
                        s->next->prev=mi;
                        t=s;
                        s=s->next;
                        delete t;
                    }
                }
                ma=ma->next;
            }
        }
        mi=mi->next;
    }
}
int main()
{
    doublelinklist h;
    h.createn(10);
    h.print();
    int min,max;
    cin>>min>>max;
    h.deletelist(min,max);
    h.print();
    system("pause");
    return 0;
}