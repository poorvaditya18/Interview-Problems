#include<bits/stdc++.h>
using namespace std;


class Solution {
public:


    int LCS(string word1,string word2 , int m , int n )
    {
        vector<vector<int>> dp(m+1,vector<int>(n+1));

        for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0 or j==0)
                {
                    dp[i][j] = 0;
                }
            }
        }

        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
                }
            }
        }
        return dp[m][n];
    }
    int minDistance(string word1, string word2) 
    {
        // minimum no of deletion = word1.length - LCS(word1,word2)

        // minimum no of insertions = word2.length - LCS(word1,word2)

        // total steps => deletion + insertion 
        int m = word1.length();
        int n = word2.length();
        int lcs = LCS(word1,word2,m,n);
        int minDeletion  = m - lcs;
        int minInsertion = n -lcs;
        return minDeletion + minInsertion;
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