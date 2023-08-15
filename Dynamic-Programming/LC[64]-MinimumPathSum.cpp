#include<bits/stdc++.h>
using namespace std;


int minPathTopDown(vector<vector<int>>&grid )
{

        // STRIVER SOLUTION -->

        // Here we do the reverse thinking --> start with bottom right and reach dest top left

        int n = grid.size();
        int m = grid[0].size();

        // Dp -->
        vector<vector<int>> dp(n,vector<int>(m,0));


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 and j==0)
                {
                    dp[i][j] = grid[i][j];
                }
                else
                {   
                    int up = grid[i][j];
                    if(i>0)
                    {
                        up += dp[i-1][j];
                    }
                    else up += 1e9;
                    int left = grid[i][j];
                    if(j>0)
                    {
                        left+= dp[i][j-1];
                    }
                    else
                    {
                        left += 1e9;
                    }

                    dp[i][j] = min(up , left);

                }
            }   
        }   

        return dp[n-1][m-1];
    }

// Memoization --> [Accepted]
int minPathSumMemoize(vector<vector<int>>& grid , int i , int j , int m ,int n,vector<vector<int>> &dp)
 {
        if( i<0 or i>=m or j<0 or j>=n)
        {
            return 0;
        }
        if(i==m-1 and j==n-1)
        {
            
            // if you reach last element or you have single element then return that element
            return grid[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int downVal = INT_MAX;
        int rightVal = INT_MAX;

        // check whethere there is any space to move down or not 
        if(i+1<m)
        {
            // then you can move down  
            downVal = grid[i][j] + minPathSumMemoize(grid,i+1,j,m,n,dp);
        }
        // check whethere there is any space to move right or not 
        if(j+1<n)
        {
            // then you can move right 
            rightVal = grid[i][j] + minPathSumMemoize(grid,i,j+1,m,n,dp);
        }

        return dp[i][j] = min(downVal,rightVal) ;

    }


// Recursive --> [TLE]
int minPathSumHelper(vector<vector<int>>& grid , int i , int j , int m ,int n)
{

	// base case 
	if( i<0 or i>=m or j<0 or j>=n)
	{
		return 0;
	}
	if(i==m-1 and j==n-1)
	{
		
		// if you reach last element or you have single element then return that element
		return grid[i][j];
	}

	// you can either move right 
	// check whethere there is any space to move right or not 
	int downVal = INT_MAX;
	int rightVal = INT_MAX;
	if(i+1<m)
	{
		// then you can move down  
		 downVal = grid[i][j] + minPathSumHelper(grid,i+1,j,m,n);
	}
	if(j+1<n)
	{
		// then you can move right 
	    rightVal = grid[i][j] + minPathSumHelper(grid,i,j+1,m,n);
	}

	return min(downVal,rightVal) ;
}


int minPathSum(vector<vector<int>>& grid) 
{
        int m = grid.size(); // no of rows 
        int n = grid[0].size(); // no of columns
        // cout<<"m : "<<m<<endl;
        // cout<<"n : "<<n<<endl;
        int i = 0; // rows
        int j = 0; // cols 

        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        
        // 					 i , j , m , n
        // return minPathSumHelper(grid,i , j , m , n);
        return minPathSumMemoize(grid,i,j,m,n,dp);
}



int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
	vector<vector<int>> grid = {
       {1,3,1},
       {1,5,1},
       {4,2,1}
    };

    cout<<minPathSum(grid)<<endl;
 
	return 0;

}