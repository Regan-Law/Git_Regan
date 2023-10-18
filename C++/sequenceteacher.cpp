#include<iostream>
using namespace std;
#define initlistsize 100 
#define increment 10

class sqlist{
  private:
    int *elem;
	int listsize;
	int length;
  public:
    sqlist();
    ~sqlist();
    void sqlistn(int n);
    void print();
    void insertlist(int i,int e);
    void deletelist(int i,int &e);
    int locatex(int x);
    void turn();
    void mergelist(sqlist &la,sqlist &lb);
};
sqlist::sqlist(){
     elem=new int[initlistsize];
     listsize=initlistsize;
     length=0;
}
sqlist::~sqlist(){
    delete [] elem;
    listsize=0;
    length=0;
}
void sqlist::sqlistn(int n){
    for(int i=0;i<n;i++)
       cin>>elem[i];
    length=n;
}
void sqlist::print(){
    for(int i=0;i<length;i++)
        cout<<elem[i]<<" ";
    cout<<endl;
 }

void sqlist::insertlist(int i,int e){
    if(i<1||i>length+1) return;
    if(length>=listsize){
      int *elem1=new int[listsize+increment];
	  for(int i=0;i<length;i++)
        elem1[i]=elem[i];
      elem=elem1;
	  listsize+=increment;
    }
    int *p=&elem[length-1],*q=&elem[i-1];
    for(;p>=q;p--) *(p+1)=*p;
    *q=e;
    length++;
}
 
void sqlist::deletelist(int i,int &e){
    if(i<1||i>length) return;
    int *p=&elem[i-1],*q=&elem[length-1];
    e = *p;
    for(;p<=q;p++) *p=*(p+1);
    length--;
   }

void sqlist::turn(){
    int *p=elem,*q=&elem[length-1];
    int *temp=new int;
    for( ;p<q;p++,q--){
        *temp=*p;
        *p=*q;
        *q=*temp;
    }
   
 }

int sqlist::locatex(int x){
    for(int i=0;i<length;i++)
       if(x==elem[i])  return i;
    return -1;
} 
void sqlist::mergelist(sqlist &la,sqlist &lb){
    int *pa=la.elem;
    int *pb=lb.elem;
	int *pc=elem;                              
   	int *pa_last=&la.elem[la.length-1];        
    int *pb_last=&lb.elem[lb.length-1];                 
    while (pa<=pa_last && pb<=pb_last)
        if(*pa<=*pb) *pc++ = *pa++;
        else *pc++= *pb++;       
    while(pa<=pa_last)
       *pc++=*pa++;
    while(pb<=pb_last)
       *pc++=*pb++;
    length=la.length+lb.length;
}
int main(){
    int e;
	sqlist l;
    l.sqlistn(10);
	l.print();
    l.insertlist(5,100);
	l.print();
    l.deletelist(7,e);
	l.print();
    l.turn();
	l.print();
    sqlist la,lb,lc;
    la.sqlistn(5);
	lb.sqlistn(5);
	la.print();
	lb.print();
	lc.mergelist(la,lb);
	lc.print();
	
 }
