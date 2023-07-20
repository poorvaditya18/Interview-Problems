#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k)
     {
        // approach using two pointers 
        int n = nums.size();
        // sort the array 
        sort(nums.begin(),nums.end());
        // keep two pointers -->
        int l =0;
        int r = 1;
        int count =0;
        while(l<n&&r<n)
        {
            // case 1: when diff < k --> right++
            if(l==r or nums[r]-nums[l]<k)
            {
                r++;
            }
            // case 2: when diff >k -->  left++
            else if(nums[r]-nums[l]>k)
            {
                l++;
            }
            // case 3: when diff == k --> left++ , also check for same element again 
            else
            {
                l++;
                count++;
                // check for same element
                while(l<n&&nums[l]==nums[l-1])
                {
                    l++;
                }
            }
        }
        
        return count;

        // approach using hashmaps ->
        // unordered_map<int,int> mpp;
        // int count = 0;

        // for(int i=0;i<nums.size();i++)
        // {   
        //     mpp[nums[i]]++;
        // }
        
        // for(auto ele:mpp)
        // {
        //   if(k==0)
        //   {
        //      if(ele.second>=2)
        //      {
        //          count++;
        //      }
        //   }
        //   else if(mpp.find(ele.first+k)!=mpp.end())
        //   {
        //       count++;
        //   }
        // }    
        // return count;
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