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
	lnode*Head;

public:
	linklist();
	~linklist();
	void createn(int n);
	void print();
	void DeleteMax();
};
linklist::linklist()
{
    Head=new lnode;
	Head=NULL;
}

void linklist::createn(int n)
{
	lnode*p,*head;
	for(int i=0;i<n;i++)
    {
		p=new lnode;
		cin>>p->data;
		p->next=NULL;
        if(head==NULL)
		{
            head=Head=p;
        }
        else
        {
            head->next=p;
        }
        head=p;
	}
    return;
}
linklist::~linklist()
{
	lnode*p;
	while(Head)
	{
		p=Head;
		Head=Head->next;
		delete p;
	}
	Head=NULL;
}
void linklist::print()
{
	lnode*p=Head;
	while(p)
	{
		cout<<p->data<<' ';
		p=p->next;
	}
	cout<<endl;
}
void linklist::DeleteMax()
{
	lnode*maxpre,*max=Head,*pre,*p;
	if(max==NULL)return;
	pre=max;p=pre->next;
	while(p)
    {
		if(p->data<=max->data)
		{ 
			pre=p;
            p=p->next;
		}
		else
		{
			maxpre=pre;
			max=p;
			pre=p;
			p=pre->next;
		}
    }
	maxpre->next=max->next;
	delete max;
}
int main()
{
	linklist h,lb;
	h.createn(10);
	h.print();
	h.DeleteMax();
	h.print();
	system("pause");
	return 0;
}