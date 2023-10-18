#include <iostream>
using namespace std;
typedef struct BiTNode{
	int data;
	BiTNode *lt;
	BiTNode *rt;
	BiTree(); 
	BiTNode *lchild;
    BiTNode *rchild;
}BiTNode;
class BiTree{
	private:
		BiTNode *bt;
		void Rcreate(BiTNode *&t);
		void InTraverse(BiTNode *t);
		int BTNodeDepth(BiTNode *t);
		BiTNode *SearchNode(BiTNode *t,char x);
	public:
	    BiTree(){bt=NULL;}
	    void RcreateBiTree();
	    void InTraverseBiTree();
	    int BTNodeDepthBiTree();
	    BiTNode *SearchNodeBiTree (char x);
		
};
 void BiTree::Rcreate(BiTNode *&t){
 	char ch;
 	cin>>ch;
 	if(ch=='.')    t=NULL;
	 else{
	 	t=new BiTNode;
	 	t->data=ch;
	 	Rcreate(t->lchild);
	 	Rcreate(t->rchild);
	     }
	 }
 void BiTree::RcreateBiTree(){
 	BiTNode  *t;
 	Rcreate(t);
 	bt=t;
 }
  void BiTree::InTraverse(BiTNode *t){
  	  if(t){
  	       InTraverse(t->lchild) ;
  	       cout<<t->data;
  	        InTraverse(t->rchild);
		   }
}
  void BiTree::InTraverseBiTree(){
  	   BiTNode *p=bt;
  	   InTraverse(p);
}
 
	int BiTree::BTNodeDepth(BiTNode *t) {
		if(t==NULL)return 0;
		else{
			int m=1+BTNodeDepth(t->lchild);
			int n=1+BTNodeDepth(t->rchild);
			if(m>=n)return m;
			else return n;	
		}	
	}
	 int BiTree::BTNodeDepthBiTree(){
	 		 BiTNode *p=bt;
			return BTNodeDepth(p);	
	 }
	 BiTNode *BiTree::SearchNode(BiTNode *t,char x){
	        BiTNode *p;
	        if(t==NULL)return NULL;
	        if(t->data>x)return t;
	        else{
	        	p=SearchNode(t->lchild,x);
	        	if(p!=NULL)return p;
	        	else return SearchNode(t->rchild,x); 
			}
	 }
	 BiTNode *BiTree::SearchNodeBiTree(char x){
	 	  BiTNode *p=bt;
	 	  return SearchNode(p,x); 	
	 }
	 
	 void main(){
	 	
	 	
	 	
	 	
	 	
	 	
	 }
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
