#include<bits/stdc++.h>
using namespace std;


string LCS(string &s1,string &s2 , int n , int m)
{
	string s;
	vector<vector<int>> dp(n+1,vector<int>(m+1));

	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<m+1;j++)
		{
			if(i==0 or j==0)
			{
				dp[i][j] = 1;
			}
		}
	}

	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<m+1;j++)
		{
			if(s1[i-1]==s2[j-1])
			{
				dp[i][j] = 1+ dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	int i=n;int j = m;
	while(i>0 and j>0)
	{
		if(s1[i-1]==s2[j-1])
		{
			s.push_back(s1[i-1]);
			i--;
			j--;
		}
		else
		{
			if(dp[i][j-1]>dp[i-1][j])
			{
				j--;
			}
			else
			{
				i--;
			}
		}
	}
	reverse(s.begin(),s.end());
	return s;
}


string findLCS(int n, int m,string &s1, string &s2)
{
	// Write your code here.	
	// n = s1.length
	// m = s2.length 

	return LCS(s1,s2,n,m);

}

int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
 
	return 0;

}