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
	linklist();//构造一个空的线性表
	~linklist();//销毁线性表
	void createn(int n);//头插法创建具有n个元素的线性链表
	void print();
	int locatex(int x);//在链表中查找是否存在元素x
	void insertlist(int i,int e);//在表中第i个位置插入元素
	void deletelist(int i,int&e);//删除表中第i个位置上的元素
	void mergelist(lnode*&ha,lnode*&hb);//合并2 个按值非递减的有序表
	lnode*gethead(){ return head;}//返回头指针
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
	{//从头结点开始，依次释放结点
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