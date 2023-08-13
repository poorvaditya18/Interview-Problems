#include<bits/stdc++.h>
using namespace std;


class Solution {
public:


    string SCS(string str1,string str2,int m ,int n)
    {
        vector<vector<int>> t(m+1,vector<int>(n+1));
        
        // base case 
       for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
                if(i==0 or j==0) t[i][j] = 0;
        
        // fill the matrix --> LCS
        for(int i=1;i<m+1;i++){
            for(int j=1; j<n+1; j++){
                if(str1[i-1] == str2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }

        // Printing LCS
        string ans = "";
        int i = m, j = n;
        while(i>0 and j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                ans.push_back(str1[i-1]);
                   i--;j--;
            }
            else
            {
                 if(t[i-1][j] > t[i][j-1])
                 {
                        ans.push_back(str1[i-1]);
                        i--;
                }
                else
                {
                    ans.push_back(str2[j-1]);
                     j--;
                 }
            }
        }
        while(i>0) {ans.push_back(str1[i-1]);i--;}
        while(j>0) {ans.push_back(str2[j-1]);j--;}
        reverse(ans.begin(), ans.end());

        return ans;

    }
    string shortestCommonSupersequence(string str1, string str2) 
    {
        // Here we need to print the shortest common supersequence 

        // we will try to find out the length of shortest common supersequence 

        // In the worst case we can have supersequence of -> ( m + n )

        // Idea is to take  the duplicate characters once --> which is eventually the LCS 

        int m = str1.length();

        int n = str2.length();

        return SCS(str1,str2,m,n);
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