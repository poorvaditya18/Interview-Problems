#include<bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    int minCostTopDown(vector<int>&cost )
    {
        int n = cost.size();
        vector<int> dp(n+1,0);
        dp[n] = 0;
        dp[n-1] = cost[n-1];
        for(int i=n-2;i>=0;i--)
        {
            // so from i= n-2 you can take one Step or two Steps 
            int val1 = dp[i+1]+cost[i];
            int val2 = dp[i+2]+cost[i];
            // store the min Value 
            dp[i] = min(val1, val2);
        }
        // finally since you can start either from 0th index or 1st index 
        // so return the minCost from where you start 
        return min(dp[0],dp[1]);
    }
    // Memoization [TLE] -->
    int minCostMemoization(vector<int>&cost , int idx,vector<int> dp)
    {
        // base case 
        if(idx>=cost.size())
        {
            return 0;
        }

        if(dp[idx]!= 0)
        {
            return dp[idx];
        }

        // choose and move one step ahead
        int oneStep = cost[idx] + minCostRecursiveHelper(cost,idx+1);
        // choose and move two step ahead 
        int twoStep = cost[idx] + minCostRecursiveHelper(cost,idx+2);

        return dp[idx] = min(oneStep,twoStep);
    }

    // Recursive Solution [TLE]--> 
    int minCostRecursiveHelper(vector<int>&cost , int idx)
    {
        if(idx>=cost.size())
        {
            return 0;
        }

        // choose and move one step ahead
        int oneStep = cost[idx] + minCostRecursiveHelper(cost,idx+1);
        // choose and move two step ahead 
        int twoStep = cost[idx] + minCostRecursiveHelper(cost,idx+2);

        return min(oneStep,twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) 
    {
        // start with index 0 
        // int startWithZero = minCostRecursiveHelper(cost,0);
        // int startWithOne = minCostRecursiveHelper(cost,1);
        //    int n = cost.size();
        //    int  startWithZero = minCostMemoization(cost,0,vector<int>(n+1,0));
        //    int startWithOne = minCostMemoization(cost , 1 , vector<int>(n+1,0));
           return minCostTopDown(cost);
        // return min(startWithZero,startWithOne);
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