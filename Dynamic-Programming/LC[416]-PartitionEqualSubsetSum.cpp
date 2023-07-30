#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

   bool subsetSumHelper(int n,int sum,vector<int>&nums,vector<vector<bool>>&dp)
   {

       for(int i=0;i<n+1;i++)
       {
           for(int j=0;j<sum+1;j++)
           {
               // initialisation step 
               if(i==0)
               {
                   dp[i][j] = false;
               }
               if(j==0)
               {
                   dp[i][j]=true;
               }

               // check condition 
               if(i-1>=0 and nums[i-1]<=j)
               {
                   // either include or exclude that element in subset
                   dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
               }
               else if (i-1>=0 and nums[i-1]>j)
               {
                   // exclude that element 
                   dp[i][j]= dp[i-1][j];
               }
           }
       }

        return dp[n][sum];
   }

    bool subsetSumProblem(vector<int>&nums,int sum)
    {
        int n = nums.size();
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1));
        return subsetSumHelper(n,sum,nums,dp);
    }

    bool canPartition(vector<int>& nums)
    {
        
        // if sum is odd then there is no way we can equally divide -> return false  
        // if sum is even then only we can equally divide   
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }

        if(sum%2!=0)
        {
            return false;
        }
        else
        {
            // check whether for sum/2 any subset is present or not
            // so this reduced to subset sum problem 
            return subsetSumProblem(nums,sum/2);
        }
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