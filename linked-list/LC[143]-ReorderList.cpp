#include<bits/stdc++.h>
using namespace std;


 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:

	// merge Linked List 
    void mergeLL(ListNode* L1, ListNode* L2)
    {   
        cout<<L1->val<<endl;
        cout<<L2->val<<endl;

        ListNode* tmp;
        while (L2->next != NULL) 
        {
          cout<<L2->val<<endl;
          tmp = L1->next;
          L1->next = L2;
          L1 = tmp;

          tmp = L2->next;
          L2->next = L1;
          L2 = tmp;
        }

    }

    // Reverse Linked List 
    ListNode* reverseLL(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp ;
        while(curr!=NULL)
        {
          temp = curr->next;
          curr->next = prev;
          prev = curr;
          curr = temp;
        }
        return prev;
    }

    // Find the middle Linked list 
    ListNode* middleLL(ListNode* head)
    {
      ListNode* slow = head; 
      ListNode* fast = head;
      while(fast!=NULL and fast->next!=NULL )
      {
        slow = slow->next;
        fast = fast->next->next; 
      }
      return slow;
    }


    void reorderList(ListNode* head) {

        if(head==NULL) return ;

        // find middle 
        ListNode* middle = middleLL(head);
     
        // reverse the second linked list 
        ListNode* rHead = reverseLL(middle);

        // merge the both linked list 
        mergeLL(head,rHead);
        
    }
};

int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	

	return 0;

}