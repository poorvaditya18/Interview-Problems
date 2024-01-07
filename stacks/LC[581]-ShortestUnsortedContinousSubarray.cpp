#include<bits/stdc++.h>
using namespace std;


class Solution {
public:



    int findUnsortedSubarray(vector<int>& nums) 
    {
    	  // Method 1  : 
          // brute force : time : o(nlogn) 
          // space : o(n)
          //  vector<int> result;
          //  vector<int> temp = nums;

          //  int start_idx=nums.size();
          //  int end_idx=-1;

          //  // sort the input array 
          //  sort(nums.begin(),nums.end());

          //  for(int i=0;i<nums.size();i++)
          //  {
          //      if(nums[i]!=temp[i])
          //      {
          //          // starting index 
          //          start_idx = min(start_idx,i);
          //      }
          //  }

          //  for(int i=nums.size()-1;i>=0;i--)
          //  {
          //      if(nums[i]!=temp[i])
          //      {
          //          // end index
          //          end_idx = max(end_idx,i);
          //      }
          //  }

          //   if(end_idx >= start_idx)
          //   {
          //       return  end_idx - start_idx + 1;
          //   }
          // return 0; // already sorted  



    	  // Method 2 : 
    	stack<int> stck_left , stck_right; // will store index
        int left_idx = nums.size();
        int right_idx = -1;
        for(int i=0;i<nums.size();i++)
        {
            while(!stck_left.empty()&& nums[i] < nums[stck_left.top()])
            {
                // current element is smaller 
                left_idx = min(left_idx , stck_left.top());

                // pop to check whether any more greater elements exists or not 
                stck_left.pop();
            }
            stck_left.push(i);
        }


        // now from right to get right_idx
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!stck_right.empty()&& nums[i] > nums[stck_right.top()])
            {
                // current element is smaller 
                right_idx = max(right_idx , stck_right.top());

                // pop to check whether any more greater elements exists or not 
                stck_right.pop();
            }
            stck_right.push(i);
        }

        if(right_idx >= left_idx)
        {
            return right_idx - left_idx + 1;
        }
        return 0;

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