#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int n = nums.size();
        if(n==1) return nums[0];
        int low =0;
        int high = nums.size()-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;

            //First check whether array is sorted or not
            if(nums[low]<nums[high])
            {
                return nums[low];
            }
            // check whether mid element
            if(mid-1>=0 && nums[mid]<nums[mid-1])
            {
                return nums[mid];
            }
            else if(mid+1<n && nums[mid+1]<nums[mid])
            {
                return nums[mid+1];
            }
            // then check mid lies in upper
            else if(nums[mid]>nums[low])
            {
                low = mid+1;
            }
            // check mid lies in lower 
            else
            {
                high = mid-1;
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