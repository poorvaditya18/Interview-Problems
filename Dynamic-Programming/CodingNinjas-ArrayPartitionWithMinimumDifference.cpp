#include<bits/stdc++.h>
using namespace std;

vector<int> subsetSumProblem(vector<int> arr , int n,int totalSum)
{
	vector<vector<bool>> dp(n+1,vector<bool>(totalSum+1));
	// do the computation work 
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<totalSum+1;j++)
		{
			if(i==0)
			{
				dp[i][j] = false;	
			}
			if(j==0)
			{
				dp[i][j] = true;
			}
			if(i-1>=0 and arr[i-1]<=j)
			{
				dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
			}
			else if (i-1>=0 and arr[i-1]>j)
			{
				dp[i][j] = dp[i-1][j]; 
			}
		}
	}

	// return the last row 
	vector<int> ans;
	for(int j=0;j<totalSum+1;j++)
	{
		if(dp[n][j]==true)
		{
			ans.push_back(j);
		}
	}

	return ans; // return the answer vector 
	

}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	
	// n -> size of array 

	// we have all the positive numbers
	//  s1,s2 = [0,range] 
	// we want s2-s1 = minimum
	// since we know s2+s1 = range(total sum) => s2 = totalsum -s2
	// therefore we want => totalSum - 2s1 = minimum 
	// now s1 will take up values half way 
	// remaining half will be for s2 
	int totalSum = 0;
	for(int i=0;i<arr.size();i++)
	{
		totalSum += arr[i];
	}

	// Now to calculate what values s1 can take 
	// we want candidate values that s1 can hold 
	// means whether it is possible for arr[] to have any subset with s1 value.
	// this problem reduces to subsetSumProblem 
	vector<int> subsetArr =  subsetSumProblem(arr,n ,totalSum);
	int mn = INT_MAX;
	for(int i=0;i<subsetArr.size();i++)
	{
		mn = min(mn,abs(totalSum-2*subsetArr[i]));
	}

	return mn ;
}


int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
 
	return 0;

}