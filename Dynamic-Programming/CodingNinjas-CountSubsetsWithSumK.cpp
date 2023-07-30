#include<bits/stdc++.h>
using namespace std;

#define ll long long 
ll t = 1e9+7;

int CountSubsetHelper(int n ,int k , vector<int>&arr, vector<vector<int>> &dp)
{
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<k+1;j++)
		{
			// initialisation condition -->
			if(i==0)
			{
				dp[i][j] = 0;
			}
			if(j==0)
			{
				dp[i][j] = 1;
			}
			if(i-1>=0 and arr[i-1]<=j)
			{
				// either include or exclude that element 
				dp[i][j] = (dp[i-1][j-arr[i-1]])%t + (dp[i-1][j])%t;
			}
			else if(i-1>=0 and arr[i-1]>j)
			{
				// dont include that element 
				dp[i][j] = (dp[i-1][j])%t;
			}
		}
	}
	return (dp[n][k])%t; // return the last cell that represents the total count when sum equals to k 
}



int findWays(vector<int>& arr, int k)
{
	// Write your code here.

	// similar to the subset sum problem with given sum , there you return true or false whether subset is present or not 
	// here you need to count the subsets with sum k 
	int n= arr.size();
	vector<vector<int>> dp(n+1,vector<int>(k+1));
	return CountSubsetHelper(n,k,arr,dp);
}



int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
 
	return 0;

}