#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

ll knapsackFuncTopDown(vector<ll> wt, vector<ll> val, ll W, ll n)
{
	// use Top Down approach to find maximum profit 
	ll dp[n+1][W+1];

	// initialise the matrix
	for(ll i=0;i<n+1;i++)
	{
		for(ll j=0;j<W+1;j++)
		{
			dp[i][j]=0;
		}
	}

	// choice diagram 
	// n , W --> i, j
	for(ll i=1;i<n+1;i++)
	{
		for(ll j=1;j<W+1;j++)
		{
			if(wt[i-1]<=j)
			{
				dp[i][j] = max( (val[i-1]+dp[i-1][j-wt[i-1]]),dp[i-1][j]  );
			}
			else if (wt[i-1]>j)
			{
				dp[i][j] = dp[i-1][j];
			}

		}
	}
	return dp[n][W];
}

int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
	ll n , W;
	cin>>n>>W;

	vector<ll> wt(n);
	vector<ll> val(n);
	for(ll i=0;i<n;i++)
	{
		cin>>wt[i]>>val[i];
	}
 	
 	cout<<knapsackFuncTopDown(wt,val,W,n)<<endl;
	return 0;

}