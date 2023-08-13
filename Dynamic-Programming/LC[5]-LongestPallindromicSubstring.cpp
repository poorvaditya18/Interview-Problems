#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    
    string LongestCommonSubstring(string a , string b , int m , int n)
    {
        string str;
        int res = 0;
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
                // if equal then consider 
                if(a[i-1]==b[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];

                    // now check substring --> whether it is a pallindrome or not 
                    // if it is pallidrome store its length 
                    if(res<dp[i][j])
                    {
                        string temp1= a.substr(i-dp[i][j],dp[i][j]);
                        string temp2 = temp1;
                        reverse(temp2.begin(),temp2.end());
                        if(temp1==temp2)
                        {
                            res = dp[i][j]; //store its length 
                            str = temp1;
                        }
                    }
                }
                else
                {
                    //dont choose 
                    dp[i][j] =0;
                }
            }
        }

        return str;
    }
    string longestPalindrome(string s) 
    {
        string a = s;
        string b(s);
        reverse(b.begin(),b.end());
        int m = a.size();
        int n = b.size();
       return  LongestCommonSubstring(a,b,m,n);
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