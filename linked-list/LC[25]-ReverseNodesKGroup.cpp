#include<bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      // default constructor 
      ListNode() : val(0), next(nullptr) {}
      // parameterised constructor 
      ListNode(int x) : val(x), next(nullptr) {}
      // constructor overrriding
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:

    // reverse the first K nodes only 
    ListNode* reverseFirstKNodes(ListNode* head ,int k)
    {
    
       ListNode* prev= NULL;
       ListNode* curr = head;
       while(k>0)
       {
           ListNode* temp = curr->next;
           curr->next = prev;
           prev = curr;
           curr = temp;
           k--;
       }
       return prev;
    }


    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        
        int count = 0;
        ListNode* ptr = head;
        while(count<k && ptr!=NULL)
        {
            ptr = ptr->next;
            count++;
        }
       
        if(count==k)
        {
            ListNode* rev_head = reverseFirstKNodes(head,k);
            head->next = reverseKGroup(ptr,k);
            return rev_head;
        }
        return head;
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