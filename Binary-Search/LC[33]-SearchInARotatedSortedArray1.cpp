#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int low = 0;
        int high = nums.size()-1;
        while(low<=high)
        {
            int mid = low +(high-low)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            // now check whehter mid lies in upper curve 
            if(nums[mid]>=nums[low])
            {
                // mid lies in the upper part 
                // means left part is sorted 
                // check whether target lies in this range or not 
                if(target>=nums[low] && target<nums[mid])
                {
                    // target lies in the left part 
                    high = mid-1;
                }
                else
                {
                    // target lies in the right part
                    low = mid+1;
                }
            }
            else
            {
                // mid lies in the lower part
                if(target>nums[mid]&&target<=nums[high])
                {
                    // right part is sorted
                    // target lies in the right part
                    low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }

        }
        return -1;
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