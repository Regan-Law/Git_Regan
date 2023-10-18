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
    int deletelist(int x);
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
        if(head->next!=NULL)
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
int doublelinklist::deletelist(int x)
{
    dnode*p=head;
    int e;
    while(p->next)
    {
        dnode*s=p->next;

        if(s->data!=x)
        {
            p=s;
            s=s->next;
        }
        else
        {
            p->next=s->next;
            if(s->next)
            {   
                s->next->prev=p;
                e=s->data;
                delete s;
            }
        } 
    }
    if(e==x)
    {
        return 1;
    }
    else
    return 0;
}
int main()
{
    doublelinklist h;
    h.createn(10);
    h.print();
    int x;
    cin>>x;
    h.deletelist(x);
    h.print();
    system("pause");
    return 0;
}