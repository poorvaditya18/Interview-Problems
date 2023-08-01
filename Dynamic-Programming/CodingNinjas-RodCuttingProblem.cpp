#include<bits/stdc++.h>
using namespace std;



// Recursive --> will give TLE 
// int cutRodHelper(vector<int>&price,vector<int>&length,int idx,int rodLength)
// {

// 	// base case
// 	if(idx==0 or rodLength==0)
// 	{
// 		return 0;
// 	}

// 	// recursive call 
// 	if(length[idx-1]<=rodLength)
// 	{
// 		return max(price[idx-1]+cutRodHelper(price, length, idx, rodLength-length[idx-1]),
// 		cutRodHelper(price, length, idx-1, rodLength));
// 	}
// 	else{
// 		return cutRodHelper(price, length, idx-1, rodLength);
// 	}


// }


// Memoization Bottom Up Approach Based 
// int cutRodHelper(vector<int>&price,vector<int>&length,int idx,int rodLength,vector<vector<int>>&dp)
// {
// 	// base case
// 	if(idx==0 or rodLength==0)
// 	{
// 		return 0;
// 	}
	
// 	// check
// 	if(dp[idx][rodLength]!=-1)
// 	{
// 		return dp[idx][rodLength];
// 	}

// 	// recursive call 
// 	if(length[idx-1]<=rodLength)
// 	{
// 		return dp[idx][rodLength] =  max(price[idx-1]+cutRodHelper(price, length, idx, rodLength-length[idx-1],dp),
// 		cutRodHelper(price, length, idx-1, rodLength,dp));
// 	}
// 	else{
// 		return dp[idx][rodLength] = cutRodHelper(price, length, idx-1, rodLength,dp);
// 	}
// }


// using Top Down Dp 
int cutRodHelper(vector<int> &price ,vector<int>&length, int n ,int rodLength)
{
	vector<vector<int>> dp (n+1,vector<int>(rodLength+1));

	// base case initialisation -->
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<rodLength+1;j++)
		{
			if(i==0 or j==0)
			{
				dp[i][j] =0;
			}
		}
	}

	//Now try to covert the the recursive call to iterative call
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			
			if(length[i-1]<=j)
			{
				dp[i][j] =  max(price[i-1]+dp[i][j-length[i-1]],
				dp[i-1][j]);
			}
			else{
				 dp[i][j] = dp[i-1][j];
			}
		}
	}

	// return maxCost 
	return dp[n][rodLength];
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	// This problem is similar to unbounded knapsack 
	// Here you can pick multiple instances of item .
	// i.e means you can have multiple instances of same length 

	int rodLength = n;

	vector<int> length(n);// this means in pieces you wan to cut the rod 
	for(int i=0;i<n;i++)
	{
		int number = i+1;
		length[i] = number; 
	}

	// intialise dp 
	// vector<vector<int>> dp (n+1,vector<int>(rodLength+1,-1)); // initialise with -1
    
 return cutRodHelper(price,length,n,rodLength);

}


int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
 
	return 0;

}