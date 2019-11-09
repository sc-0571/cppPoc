#include <bits/stdc++.h>

using namespace std;
struct node{
	int data;
	node* next;
};
node* create(int Array[]){
	node *p,*pre,*head;
	head=new node;head->next=NULL;pre=head;
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
int search(node* head,int x){
	int count=0;
	node* p=head->next;
	while(p!=NULL)
	{
		if(p->data==x){
			count++;
		}
		p=p->next;
	}
	return count;
}
int main() {
	int Array[5]={5,3,6,1,2};
	node* L=create(Array);
	int x;cin>>x;
	int num=search(L,x);
	if(num==0){
		cout<<"没找到"<<x;
	}
	else{
		cout<<"找到了"<<num<<"个"<<x;
	}
	return 0;
}