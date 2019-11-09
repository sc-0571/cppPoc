#include <bits/stdc++.h>

using namespace std;
struct node{
	int data;
	node* next;
}; 
node* create(int Array[]){
    node *p,*pre,*head; 
    head=new node; 
    head->next=NULL;
    pre=head; 
    for(int i=0;i<5;i++){
        p=new node;
		p->data=Array[i];
        p->next=NULL;
        pre->next=p;
        pre=p;
    }
    return head;  
}
void insert(node *head,int pos,int x){
	node* p=head;
	for(int i=1;i<=pos-1;i++){
		p=p->next;
	}
	node *q=new node;
	q->data=x;
	q->next=p->next;
	p->next=q;
}
int main() {
	int Array[5]={5,3,6,1,2};
	node* L=create(Array);
	int x=4;
	insert(L,3,x);
	L=L->next;
	while(L!=NULL)
	{
		cout<<(L->data)<<" ";
		L=L->next;
	}
    return 0;
}