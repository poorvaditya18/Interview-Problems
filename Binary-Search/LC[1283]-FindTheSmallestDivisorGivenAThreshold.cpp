#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int low =  1;
        int high = *max_element(begin(nums),end(nums));
        int ans= -1;
        while(low<=high)
        {
            int mid = low +(high-low)/2;

            if(checkFunc(nums,mid,threshold))
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }

    bool checkFunc(vector<int>&nums,int mid,int threshold)
    {
        int sum =0;
        for(int i=0;i<nums.size();i++)
        {
            sum+= (nums[i]+mid-1)/mid;
            if(sum>threshold)
            {
                return false;
            }
        }
        return true;
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