#include<bits/stdc++.h>
using namespace std;


#define INF INT_MAX-1
class Solution {
public:

    int minCoin(vector<int>& coins , int n , int amount )
    {
        vector<vector<int>> dp(n+1,vector<int>(amount+1));

        // base case , 1st row and 1st column initialisation
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<amount+1;j++)
            {
                if(i==0)
                {
                    // means suppose you have coins[]={} , sum = 1 , then minimum no of coins required to sum up to amount = 1 will be infinite . as you dont have coins 
                    dp[i][j] = INF;
                }
                if(j==0)
                {
                    // means suppose you have coins[]= {1,2} and amount = 0; then minimum coins required to sum up to amount = 0
                    dp[i][j]= 0;
                }
            }
        }
        // TWIST-->
        // for second row 
        // Reason --> if coins[] ={1} and sum = {3} , then you can have 3 coins 1+1+1 = 3
        // so if you have coins[]={3} and sum = {4}, then you have infinite coins 
        for(int j=1;j<amount+1;j++)
        {  
                    if (j % coins[0] == 0)
                        dp[1][j] = j / coins[0];
                    else
                        dp[1][j] = INF;   
        }
       

        for(int i=2;i<n+1;i++)
        {
            for(int j=1;j<amount+1;j++)
            {
                if(coins[i-1]<=j)
                {
                    // you can pick that coin(multiple instances) or dont pick
                    // if you pick the increase the count as 1;
                    dp[i][j] = min( dp[i][j-coins[i-1]] + 1, dp[i-1][j]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        // finally check last index--> dp[n][amount]
        if(dp[n][amount]==INF)
        {
            return -1;
        }
        return dp[n][amount];
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        // Here we want Minimum no of coins required to sum up to "amount"

        int n = coins.size();
        return minCoin(coins,n,amount);
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