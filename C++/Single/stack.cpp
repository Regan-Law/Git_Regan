#include<iostream>
using namespace std;
#define initstacksize 100
#define increment 10
class sqstack
{
private:
	char*base;
	char*top;
	int stacksize;

public:
	sqstack();
	void push(char e);
	void pop(char&e);
	int emptystack();
	void reverse(char*st);
};
sqstack::sqstack()
{
	base=top=new char[initstacksize];
	stacksize=initstacksize;
}
void sqstack::push(char e)
{
	if(top-base>=stacksize)
	{
		char*base1=new char[stacksize+increment];
		for(int i=0;i<stacksize;i++)
			base1[i]=base[i];
		delete[] base;
		base=base1;
		top=base+stacksize;
		stacksize+=increment;
	}
	*top++=e;
}
void sqstack::pop(char&e)
{
	if(top==base)
		return;
	e=*--top;
}
int sqstack::emptystack()
{
	if(top==base)
		return 1;
	else
		return 0;
}
void sqstack::reverse(char*st)
{
	char e;

	while(*st)
	{
		push(*st);
		st++;
	}
	while(!emptystack())
	{
		pop(e);
		cout<<e;
	}
}
int main()
{
	sqstack s;
	//	s.initstack();
	char*st=new char[255];
	cin>>st;
	s.reverse(st);
}
