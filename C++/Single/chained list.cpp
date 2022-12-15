#include<iostream>
using namespace std;
typedef struct lnode
{
	int data;
	lnode*next;
}lnode;
class linklist
{
private:
	lnode*head;
public:
	linklist();//����һ���յ����Ա�
	~linklist();//�������Ա�
	void createn(int n);//ͷ�巨��������n��Ԫ�ص���������
	void print();
	int locatex(int x);//�������в����Ƿ����Ԫ��x
	void insertlist(int i,int e);//�ڱ��е�i��λ�ò���Ԫ��
	void deletelist(int i,int&e);//ɾ�����е�i��λ���ϵ�Ԫ��
	void mergelist(lnode*&ha,lnode*&hb);//�ϲ�2 ����ֵ�ǵݼ��������
	lnode*gethead(){ return head;}//����ͷָ��
	void reverse();
	void DeleteMax();

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
	{//��ͷ��㿪ʼ�������ͷŽ��
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
int linklist::locatex(int x)
{
	lnode*p=head->next;
	while(p)
	{
		if(p->data==x)return 1;
		else p=p->next;
	}
	return 0;
}
void linklist::insertlist(int i,int e)
{
	lnode*p=head;
	int j=0;
	while(p&&j<i-1)
	{ 
		p=p->next;j++;
	}
	if(!p||j>i-1)
	return;
	lnode*s=new lnode;
	s->data=e;
	s->next=p->next;
	p->next=s;
}
void linklist::deletelist(int i,int&e)
{
	lnode*p=head;
	int j=0;
	while(p->next&&j<i-1)
	{ 
		p=p->next;j++;
	}
	if(!p->next||j>i-1)
	return;
	lnode*s=p->next;
	e=s->data;
	p->next=s->next;
	delete s;
}
void linklist::mergelist(lnode*&ha,lnode*&hb)
{
	lnode*pa=ha->next,*pb=hb->next,*pc=ha;
	while(pa&&pb)
		if(pa->data<=pb->data)
		{
			pc->next=pa;pc=pa;pa=pa->next;
		}
		else
		{ 
			pc->next=pb;pc=pb;pb=pb->next;
		}
	if(pa)pc->next=pa;
	else pc->next=pb;
}
void linklist::reverse()
{
	lnode*p=head->next,*q,*qr;
	if(p==NULL||p->next==NULL)
	return;
	qr=p->next;
	p->next=NULL;
	while(qr->next)
	{
		q=qr->next;
		qr->next=p;
		p=qr;
		qr=q;
	}
	qr->next=p;
	head->next=qr;
}

void linklist::DeleteMax()
{
	lnode*maxpr=head,*maxp=head->next,*pr,*p;
	if(maxp==NULL)return;
	pr=maxp;p=pr->next;
	while(p!=NULL)
		if(p->data<=maxp->data)
		{ 
			pr=p;p=p->next;
		}
		else
		{
			maxpr=pr;
			maxp=p;
			pr=p;
			p=pr->next;
		}
	maxpr->next=maxp->next;
	delete maxp;
}
int main(){
	linklist h;
	h.createn(10);
	h.print();
	h.insertlist(5,100);
	h.print();
	int e;
	h.deletelist(6,e);
	h.print();
	h.reverse();
	h.print();
	h.DeleteMax();
	h.print();
	linklist ha,hb;
	ha.createn(5);
	hb.createn(5);
	lnode*la=ha.gethead();
	lnode*lb=hb.gethead();
	ha.mergelist(la,lb);
	ha.print();
}