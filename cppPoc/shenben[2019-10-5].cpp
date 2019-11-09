#include <bits/stdc++.h>

using namespace std;
struct node{
	int data;
	node* next;
};
node* create(int Array[]){
    node *p, *pre, *head;
    head=new node;
    head->next=NULL;
    pre=head;
    for(int i=0;i<5;i++)
	{ 
        p=new node;
		p->data=Array[i];
        p->next=NULL;
        pre->next=p;
        pre=p;
    }
    return head;  
}
void del(node *head,int x){
	node* p=head->next;
	node* pre=head;
	while(p!=NULL){
		if(p->data==x){
			pre->next=p->next;
			delete(p);
			p=pre->next;
		}
		else{
			pre=p;
			p=p->next;
		}
	}
}
int main() {
	int Array[5]={5,3,6,1,2};
	node *L=create(Array);
	int x;cin>>x;del(L,x);
	L=L->next;
	while(L!=NULL){
		cout<<(L->data)<<" ";
		L=L->next;
	}
    return 0;
}