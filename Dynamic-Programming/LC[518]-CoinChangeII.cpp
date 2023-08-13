#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int coinWays(vector<int>& coins, int n ,int amount)
    {
        vector<vector<int>> dp(n+1,vector<int>(amount+1));

        // base case 
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<amount+1;j++)
            {
                if(i==0)
                {
                    dp[i][j]=0;
                }
                if(j==0)
                {
                    dp[i][j] = 1;
                }
            }
        }

        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<amount+1;j++)
            {
                //check 
                if(coins[i-1]<=j)
                {
                    // then you can either choose (then you have multiple instances)or dont choose 
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                }
                else
                {
                    // you cannot choose 
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }
    int change(int amount, vector<int>& coins) 
    {
        // Here we want maximum no of ways that can sum up to "amount"
        // similar to subset sum 
        // and unbounded knapsack 
        int n = coins.size();
        return coinWays(coins,n,amount);
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