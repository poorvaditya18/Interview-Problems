#include<bits/stdc++.h>
using namespace std;

// Add two numbers 
  
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* p1, ListNode* p2) 
    {
        // using two pointer and dummyNode
        // dumy node
        ListNode* temp = new ListNode();
        ListNode* oldHead = temp;

        int carry = 0; // initialise carry as 0 

        while(p1!=NULL and p2!=NULL)
        {

            // find sum 
            int sum = p1->val + p2->val + carry;

            if(sum<10)
            {
                // means sum does not have carry 
                ListNode* newNode = new ListNode(sum);
                // linking 
                temp->next = newNode;
                temp = temp->next;
                carry = 0;
            }
            else if (sum>=10)
            {
                // sum will have carry 
                carry = sum/10;
                int rem = sum%10;
                ListNode* newNode = new ListNode(rem);
                // link with new node 
                temp->next = newNode;
                temp = temp->next;
            }

            // move the pointers 
            p1 = p1->next;
            p2 = p2->next;
        }
        
        // edge cases 
        while(p1!=NULL)
        {
            // means only list 1 is left 
            int sum = p1->val + carry;
            if(sum<10)
            {
                // means sum does not have carry 
                
                ListNode* newNode = new ListNode(sum);
                // linking 
                temp->next = newNode;
                temp = temp->next;
                carry = 0;
            }
            else if (sum>=10)
            {
                // sum will have carry 
                carry = sum/10;
                int rem = sum%10;
                ListNode* newNode = new ListNode(rem);
                // link with new node 
                temp->next = newNode;
                temp = temp->next;
            }
            p1 = p1->next;
        }

        while(p2!=NULL)
        {
            // means only list 1 is left 
            int sum = p2->val + carry;
            if(sum<10)
            {
                // means sum does not have carry 
                ListNode* newNode = new ListNode(sum);
                // linking 
                temp->next = newNode;
                temp = temp->next;
                carry = 0;
            }
            else if (sum>=10)
            {
                // sum will have carry 
                carry = sum/10;
                int rem = sum%10;
                ListNode* newNode = new ListNode(rem);
                // link with new node 
                temp->next = newNode;
                temp = temp->next;
            }
            p2 = p2->next;
        }

        // check whether any carry is left or not 
        if(carry!=0)
        {
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
            temp = temp->next;
        }

        return oldHead->next;
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