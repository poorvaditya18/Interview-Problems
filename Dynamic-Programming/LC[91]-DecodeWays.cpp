#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    int numDecodingsHelper(string s , int idx,vector<int>dp)
    {
        // base case
        if(idx>=s.size())
        {
            return 1;
        }

        if(dp[idx]!=-1)
        {
            return dp[idx];
        }
        int res =0 ;
        // you have choices 
        // you can choose one element and get remaining no of ways from i+1 elements
        if(s[idx]!= '0')
        {
            res += numDecodingsHelper(s,idx+1,dp);
        }
        // or you can choose two element and get remaing no of ways from i+2 elements 
        // elements will have range as 1 , 2 , or less than 26 .
        if( idx+1<s.size() and (s[idx]=='1' or s[idx]=='2' && s[idx+1]<='6'))
        {
            res += numDecodingsHelper(s,idx+2,dp);
        }
        return dp[idx]= res;
    }
    int topDownNumDecodings(string s , vector<int> dp)
    {
        int n = s.size();
        // Basae Initialisation -->
        for(int i=0;i<n+1;i++)
        {
            dp[i]=0;
        }
        dp[0]=1;
        if(s[0]!='0')
        {
            dp[1] = 1;
        }
        else
        {
            dp[1]=0;
        }

        for(int i=2;i<n+1;i++)
        {
            //cases 
            // you can choose single element
            if(s[i-1]!='0')
            {
                dp[i] += dp[i-1];
            }
            // also you can choose double element 
            // so you can choose substring from i - 2, of size 2
            int substr = stoi(s.substr(i-2,2));
            if(substr>=10 && substr <=26)
            {
                dp[i]+= dp[i-2];
            } 
        }
        return dp[n];
    }
    int numDecodings(string s) 
    {
        int n = s.size();
        vector<int> dp(n+1);
       return topDownNumDecodings(s ,dp);
    }
};

int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
	string s = "11106";
	cout<<numDecodings(s)<<endl;
 
	return 0;

}