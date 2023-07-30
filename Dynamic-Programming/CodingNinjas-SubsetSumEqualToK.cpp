#include<bits/stdc++.h>
using namespace std;

// subset Sum helper function 

bool subsetSumHelper(int n,int k, vector<int>&arr , vector<vector<bool>> &dp)
{
    
    // start with the first cell 
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<k+1;j++)
        {
             // same as knapsack 
             // here also we have choice 

             // if element is less than k then you can either include or exclude 
             if(arr[i-1]<=j)
             {
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
             }
             else
             {
                 // if element is greater than k then you cannot include 
                 dp[i][j] = dp[i-1][j];
             }
        }
    }
    
    return dp[n][k]; // finally return the last cell answer. 
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Subset Sum Problem --> Similar to knapsack variation 

    //dp
    vector<vector<bool>> dp(n+1,vector<bool>(k+1));

    // initialisation of dp 
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<k+1;j++)
        {
            if(i==0)
            {
                dp[i][j]= false;
            }
            if(j==0)
            {
                dp[i][j] = true;
            }
        }
    }

    return subsetSumHelper(n , k , arr , dp);
    
}



int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
 
	return 0;

}