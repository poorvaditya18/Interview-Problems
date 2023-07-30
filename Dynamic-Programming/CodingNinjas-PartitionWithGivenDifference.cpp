#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll mod = 1e9+7;
int countNoOfSubset(vector<int> &arr , int n ,int sum)
{

    vector<vector<int>> dp(n+1,vector<int>(sum+1));

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
            {
                dp[i][j] = 0;
            }
            if(j==0)
            {
                dp[i][j]= 1;
            }
            if(i-1>=0 and arr[i-1]<=j)
            {
                // choice : either include or exclude 
                dp[i][j] = (dp[i-1][j-arr[i-1]])%mod + (dp[i-1][j])%mod;
            }
            else if(i-1>=0 and arr[i-1]>j)
            {
                // dont include 
                dp[i][j] = (dp[i-1][j])%mod;
            }

        }
    }

    return (dp[n][sum])%mod;// return the last cell indicating the count of subsets with given sum 

}


int countPartitions(int n, int d, vector<int> &arr) 
{
    // Write your code here.
    // we want s1 - s2 = diff
    // we have s1 + s2 = sumOfArray 
    // so equation reduced to => s1 = (diff + sumOfArray)/2;
    int sum = 0;
    for(int i=0;i<arr.size();i++)
    {
        sum+= arr[i];
    }
    // calculate s1 because -> we will find the count of subsets whose sum is s1 . 
    // this reduces to count no of subset with a given sum problem . 

    //edge case  -->  since we cannot have negative value of sum and we cannot have decimal value.
    if(sum-d <0 || (sum-d)%2 ) return 0;

    int s1 = (sum+d)/2;

    return countNoOfSubset(arr,n,s1);
}




int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
 
	return 0;

}