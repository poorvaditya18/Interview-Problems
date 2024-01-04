#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        
       // nums2 = [1,3,4,2]
       stack<int> stck; // will store nums2 indexes
       
       vector<int> output(nums2.size()); // will store nge of nums2 
       vector<int> result(nums1.size());
       stck.push(0);

       for(int i=1;i<nums2.size();i++)
       {
           while(!stck.empty() && nums2[i]>nums2[stck.top()])
           {
               output[stck.top()]= nums2[i];
               stck.pop();
           }
           stck.push(i);
       }

        // mark the remaining element as -1 
       while(!stck.empty())
       {
           int topIdx = stck.top();
           output[topIdx] = -1 ;
           stck.pop();
       }

       for(int i=0;i<nums1.size();i++)
       {
           auto it = find(nums2.begin(),nums2.end(), nums1[i]);
           if(it!= nums2.end())
           {
               int idx = it - nums2.begin();
               result[i] = output[idx];
           }
       }

       return result;
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