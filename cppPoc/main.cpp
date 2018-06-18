#include<iostream>
int a[6];
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret=NULL;
        int increase = 0;
        ListNode* result = NULL;
        while(l1 && l2) {
            int temp = l1->val+ l2->val + increase;
            increase = temp/10;
            temp = temp%10;
            ListNode newNode(temp);
            if (result == NULL) {
                result = &newNode;
                ret = &newNode;
            } else {
                ret->next = &newNode;
            }
               
            ret = &newNode;

            l1 = l1->next;
            l2 = l2->next;
        } 
        /*
        while(l1) {
            int temp = l1->val + increase;
            increase = temp/10;
            temp = temp%10;
            l1 = l1->next;
            ListNode newNode(temp);
            ret->next = &newNode;
            ret = &newNode;
            
        }
        while(l2) {
            int temp = l2->val + increase;
            increase = temp/10;
            temp = temp%10;
            l2 = l2->next;
            ListNode newNode(temp);
            ret->next = &newNode;
            ret = &newNode;
        }*/
        return result;
}
    
int main1()
{ 
  int n,i;
  ListNode* ret = NULL;
  ListNode* result = NULL;
  for( i=1;i<6;i++)
  {
  	ListNode* node = new ListNode(i); 
  	if (i == 1) {
  		result = node;
  		ret = node;
  	} else {
  		ret->next = node;
  		ret = node;
  	}
  	
  } 
  int k =0;
  while(result != NULL && k++ < 10) {
  	cout << result->val << endl;
  	result = result->next;
  }
 
  return 0;
} 
