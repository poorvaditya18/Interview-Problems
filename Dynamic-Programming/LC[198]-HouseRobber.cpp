#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    // int robRecursiveHelper(vector<int>&nums,int index)
    // {
    //     // Recursive solution
    //     if(index==0)
    //     {
    //         return nums[index];
    //     }
    //     if(index<0) return 0;

    //     // You have two options -> either pick or not 

    //     // choose the element then you cannot pick adjacent element
    //     int pick = nums[index] + robHelper(nums,index-2);

    //     // dont choose the element, see the remaining element 
    //     int notPick = robHelper(nums,index-1); 

    //     return max(pick ,notPick);
    // }

    //  Memoization Bottom Up Approach --> 
    int rob(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(n-1,nums,dp);
    }


    // int f(int ind,vector<int>& nums, vector<int>& dp)
    // {
    //     if(ind==0) return nums[ind];
    //     if(ind<0) return 0;
    //     if(dp[ind]!=-1) return dp[ind];
    //     int pick= nums[ind]+ f(ind-2,nums,dp);
    //     int notPick= f(ind-1,nums,dp);
    //     return dp[ind]=max(pick,notPick);
    // }

    // using Top Down Approach Dp  to avoid Recursive calls  ->
    int f(int ind,vector<int>&nums,vector<int>&dp)
    {
        // initialisation 
        int n = nums.size();
        dp[0] = nums[0]; //base initialisation 
        for(int i=1;i<nums.size();i++)
        {
            int pick = nums[i];
            if(i>1) pick += dp[i-2];
            int notPick = dp[i-1];  
            dp[i] = max(pick , notPick);
        }
        return dp[n-1];
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