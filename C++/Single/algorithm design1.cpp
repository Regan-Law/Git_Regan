#include<iostream>
using namespace std;
typedef struct lnode
{
	int data;
	lnode*next;
} lnode;
class linklist
{
private:
	lnode*head;

public:
	linklist();
	~linklist();
	void createn(int n);
	void print();
	lnode*gethead()
	{
		return head;
	}
	void Inserthb(lnode*&ha,lnode*&hb);
};
linklist::linklist()
{
	head=new lnode;
	head->next=NULL;
}

void linklist::createn(int n)
{
	lnode*p;
	for(int i=0;i<n;i++){
		p=new lnode;
		cin>>p->data;
		p->next=head->next;
		head->next=p;
	}
}
linklist::~linklist()
{
	lnode*p;
	while(head)
	{
		p=head;
		head=head->next;
		delete p;
	}
	head=NULL;
}
void linklist::print()
{
	lnode*p=head->next;
	while(p)
	{
		cout<<p->data<<' ';
		p=p->next;
	}
	cout<<endl;
}
void linklist::Inserthb(lnode*&ha,lnode *&hb)
{
	ha=head;
	lnode *p=hb;
	int length=0;
	while(ha)
	{		
		if(ha->data%2==0)
		{
			lnode *s=new lnode;
			s->data=ha->data;
			s->next=p->next;	
			p->next=s;		
			p=s;
			length++;			
		}
		ha=ha->next;		
	}
	lnode *t=hb;
	for(int i=0;i<length-1;i++)
	{
		while(t->next)
		{
			if(t->data>t->next->data)
			{
				int temp=t->data;
				t->data=t->next->data;
				t->next->data=temp;
			}
			t=t->next;
		}
		t=hb;
	}
}
int main()
{
	linklist h,lb;
	h.createn(10);
	h.print();
	lnode*ha=h.gethead();
	lnode*hb=lb.gethead();
	h.Inserthb(ha,hb);
	h.print();
	lb.print();
	system("pause");
	return 0;
}