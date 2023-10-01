#include<bits/stdc++.h>
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head==NULL)
        {
            return NULL;
        }
        if(head->next==NULL)
        {
            return head;
        }
        ListNode* oddHead = head;
        ListNode* odd = head;
        ListNode* evenHead = head->next;
        ListNode* even = head->next;
        while(even!=NULL and odd!=NULL)
        {
            if(even!=NULL)
            {
                odd->next = even ->next;
                odd = odd->next;
            }
            if(odd!=NULL)
            {
                even->next= odd->next;
                even = even ->next;
            }
        }
        while(oddHead->next!=NULL)
        {
            oddHead = oddHead->next;
        }
        oddHead->next = evenHead;
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