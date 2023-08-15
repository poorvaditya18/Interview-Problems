#include<bits/stdc++.h>
using namespace std;



// Top Down --> 
int uniquePathsTopDown(int m ,int n)
{
	vector<vector<int>> dp(m,vector<int>(n,0));
                // base case
                for(int i=0;i<m;i++)
                {
                        for(int j=0;j<n;j++)
                        {
                                if(i==0 and j==0)
                                {
                                        // from base case it can be one way 
                                        dp[i][j] = 1;
                                }
                                else
                                {       
                                        int up=0;
                                        if(i>0)
                                        {
                                          up = dp[i-1][j];
                                        }
                                        int left = 0;
                                        if(j>0)
                                        {
                                          left = dp[i][j-1];
                                        }
                                
                                        dp[i][j] = up + left;
                                }
                        }
                }
                return dp[m-1][n-1];
}


// Memoization --> [Accepted]
 int uniquePathsMemoization(int m ,int n , int i , int j,vector<vector<int>>&dp)
 {
         // base case 
        if( i<0 or i>=m or j<0 or j>=n)
        {
            return 0;
        }

        if(i==m-1 && j==n-1)
        {
           return 1;
        }

        if(dp[i][j]!=-1)
        {
                return dp[i][j];
        }

        return dp[i][j] = uniquePathsMemoization(m,n,i,j+1,dp) + uniquePathsMemoization(m,n,i+1,j,dp);  
 }


// Recursive -- > [TLE]
int uniquePathsHelper(int m ,int n , int i , int j,int count )
{
        // base case 
        if( i<0 or i>=m or j<0 or j>=n)
        {
            return 0;
        }

        if(i==m-1 && j==n-1)
        {
           count++;
           return count;
        }

        return uniquePathsHelper(m,n,i,j+1,count) + uniquePathsHelper(m,n,i+1,j,count);  
         
}


int uniquePaths(int m, int n)
{
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        // return uniquePathsHelper(m, n , 0 , 0,0);
        return uniquePathsMemoization(m,n,0,0,dp);
}



int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
 	cout<<uniquePaths(3,2)<<endl;
	return 0;

}