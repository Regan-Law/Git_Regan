#include<iostream>
using namespace std;
typedef struct lnode
{
	int coef;
	int exp;
	lnode*next;
} lnode;
class poly
{
	lnode*head;

public:
	void create(int n);//创建n项的多项式
	int compare(int a,int b);
	void addpoly(poly&ha,poly hb);
	void print();
};
void poly::create(int n)
{
	head=new lnode;
	head->next=NULL;
	lnode*p;
	for(int i=0;i<n;i++)
	{
		p=new lnode;
		cin>>p->coef>>p->exp;//升序输入
		p->next=head->next;
		head->next=p;
	}
}
int poly::compare(int a,int b)
{
	if(a>b)
		return-1;
	else if(a==b)
		return 0;
	else
		return 1;
}
void poly::addpoly(poly&ha,poly hb)
{
	lnode*q=ha.head,*pa=ha.head->next,*pb=hb.head->next,*r;
	while(pa&&pb)
		switch(compare(pa->exp,pb->exp))
		{
		case-1:
			q=pa;
			pa=pa->next;
			break;
		case 0:
			pa->coef+=pb->coef;
			if(pa->coef==0)
			{
				q->next=pa->next;
				delete pa;
				pa=q;
			}
			else
				q=pa;
			pa=pa->next;
			pb=pb->next;
			break;
		case 1:
			r=new lnode;
			r->coef=pb->coef;
			r->exp=pb->exp;
			q->next=r;
			r->next=pa;
			q=r;
			pb=pb->next;
			break;
		}
	while(pb !=NULL)
	{
		r=new lnode;
		r->coef=pb->coef;
		r->exp=pb->exp;
		q->next=r;
		r->next=pa;
		q=r;
		pb=pb->next;
	}
}
void poly::print()
{
	lnode*p=head->next;
	while(p)
	{
		cout<<p->coef<<' '<<p->exp<<' ';
		p=p->next;
	}
	cout<<endl;
}
int main()
{
	poly ha,hb;
	ha.create(5);
	hb.create(4);
	ha.print();
	hb.print();
	ha.addpoly(ha,hb);
	ha.print();
	system("pause");
	return 0;
}