#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        // int low = 0;
        // int high = nums.size()-1;

        // while(low<high)
        // {
        //     int mid = (low+high)/2;
        //     if(mid%2 ==1)
        //     {
        //         mid--;
        //     }
        //     if(nums[mid]!=nums[mid+1])
        //     {
        //         high = mid;
        //     }
        //     else
        //     {
        //         low = mid+2;
        //     }
        // }
        // return nums[low];


			
        // Intuition-->
        // since array is sorted 
        // Since we want to search an element
        // Therefore use binary Search 

        int n = nums.size();
        int lo = 0;
        int hi = n-1;

        while(lo<hi)
        {
            int mid = lo + (hi-lo)/2;
            
            //check whether halves are even or not 
            bool halvesEven = (hi-mid)%2==0;

            //check partner 

            //partner lies in right 
            if(nums[mid]==nums[mid+1])
            {
                if(halvesEven)
                {
                    lo=mid+2;
                }
                else
                {
                    hi=mid-1;
                }
            }
            // partner lies in left 
            else if(nums[mid]==nums[mid-1])
            {
                if(halvesEven)
                {
                    hi = mid-2;
                }
                else
                {
                    lo = mid+1;
                }
            }
            else
            {
                // means element does not have its duplicate partner
                return nums[mid];
            }
        }

        return nums[lo];
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