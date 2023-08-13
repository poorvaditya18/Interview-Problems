#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int LCS(string a,string b ,int m , int n)
    {

        vector<vector<int>> dp(m+1,vector<int>(n+1));

        // base case 
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

                // if same then include both  a[m-1] == b[n-1]
                if(a[i-1]==b[j-1])
                {
                    // include both the elements
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    // you can include either of them 
                    // since we want longest therefore take maximum from them 
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    int longestPalindromeSubseq(string a) 
    {

        int m = a.length();

        string b(a);

        reverse(b.begin(), b.end());

        int n = b.length();

        return LCS(a,b,m,n);
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