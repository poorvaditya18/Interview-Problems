#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int countNoOfSubsets(vector<int>&nums,int k)
    {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1));

        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<k+1;j++)
            {
                if(i==0)
                {
                    dp[i][j] = 0;
                }
                if(j==0)
                {
                    dp[i][j] = 1;
                }
                if(i-1>=0 and nums[i-1]<=j)
                {
                    // choice : either include or exclude 
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
                if(i-1>=0 and nums[i-1]>j)
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    
     return dp[n][k];    

    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // this is similar to Count no of subset with minimum difference 
        // By placing signs we are getting s1 - s2 = target 
        // s1 = (diff + SumArr)/2;
        int sum =0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        // so we need find out the possible subsets which can have sum as s1 .

        // base check  -->  since we cannot have negative value of sum and we cannot have decimal value.
        if((sum-target)%2!=0 or (sum-target)<0) return 0;

        // we will check whether for this s2 how many subsets exists. 
        int s2 = (sum  - target)/2;
       
       return countNoOfSubsets(nums,s2); 
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