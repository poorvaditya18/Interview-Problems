#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
static ll dp[101][100001];



// ll knapsackFunc(vector<ll> &wt, vector<ll> &val,ll W,ll n)
// {


// 	// recursive knapsack 

// 	// no items or bag capacity becomes zero 
// 	if(n==0 or W==0) return 0;

// 	if(wt[n-1]<=W)
// 	{
// 		// choice -> take or dont take 
// 		return max((val[n-1]+knapsackFunc(wt,val,W-wt[n-1],n-1)),knapsackFunc(wt,val,W,n-1));
// 	}
// 	else 
// 	{
// 		// dont take that item 
// 		return knapsackFunc(wt,val,W,n-1);
// 	}

// }


ll knapsackFuncMemoize(vector<int> &wt, vector<ll> &val , int W , int n)
{
	// we  will store profit in the matrix
	if(n==0 or W==0) return 0;

	// before calling recursive function check value in the matrix present or not 
	if(dp[n][W]!=-1)
	{
		return dp[n][W];
	}

	if(wt[n-1]<=W)
	{
		return dp[n][W] = max((val[n-1]+knapsackFuncMemoize(wt,val,W-wt[n-1],n-1)),knapsackFuncMemoize(wt,val,W,n-1));
	}
	else
	{
		return dp[n][W] = knapsackFuncMemoize(wt,val,W,n-1);
	}


}



int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
 memset(dp,-1,sizeof(dp));	
 int n,W; // n-> no of items , W -> maximum bag capacity 
 cin>>n>>W;


 vector<int> wt(n); // weight array
 vector<ll> val(n); // value array 

 for(int i=0;i<n;i++)
 {
 	cin>>wt[i]>>val[i];
 }

 ll maxProfit = knapsackFuncMemoize(wt,val,W,n);
 cout<<maxProfit<<endl;



	return 0;

}