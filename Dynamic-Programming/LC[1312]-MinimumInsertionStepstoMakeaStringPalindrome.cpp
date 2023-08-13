#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int LCS(string s1, string s2, int m ,int n)
    {
        vector<vector<int>> dp(m+1,vector<int>(n+1));

        for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0 or j==0)
                {
                    dp[i][j]=0;
                }
            }
        }


        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]= 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    // this function will find out the length of longest pallindromic string 
    int LPS(string s1)
    {   
        // LPS(s) = LCS(s,reverse(s))
        int m = s1.length();
        string s2(s1);
        reverse(s2.begin(),s2.end());
        int n = s2.length();
        return LCS(s1,s2,m,n);
    }
    int minInsertions(string s)
    {
       // intuition --> no of minimum insertions = no of minimum deletions 
        int n = s.length();

        return n - LPS(s);
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