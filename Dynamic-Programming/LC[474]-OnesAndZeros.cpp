#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // 3 things are changing here -> strs, m , n 
    int dp[601][101][101]; 
    

    pair<int,int> countOnesZeros(string s)
    {   
        int one = 0, zero = 0;
        
        for(int i = 0; i < s.length(); i++) // travel in the string
        {
            if(s[i] == '1') // if == '1', then add to one
                one++;
            else            // otherwise add to zero
                zero++;
        }
        
        return {one, zero};
    }

    // Recursive Approach --> [ TLE ]
    // int Helper(vector<string>&strs ,int one ,int zero , int& maxZero , int& maxOne ,int i)
    // {
    //     // base case
    //     if(i>=strs.size())
    //     {
    //         return 0;
    //     }

    //     if(one > maxOne || zero > maxZero)
    //         return 0;

    //     // check 
    //     pair<int,int> p = countOnesZeros(strs[i]);

    //     int pick  = 0;
    //     int notPick = 0;
    //     int rem = 0;
    //     if(one + p.first <= maxOne && zero + p.second <= maxZero)
    //     {
    //         // ans1, including it in our answer
    //         pick = 1 + Helper(strs, one + p.first, zero + p.second, 
    //                        maxZero, maxOne, i+1);
            
    //         // not including in our answer.
    //         notPick = Helper(strs, one, zero, maxZero, maxOne, i+1); 
    //     }
    //     else // if crossing limit, obviously not to take
    //     {
    //        rem = Helper(strs, one, zero, maxZero, maxOne, i+1);
    //     }
    //     return max({pick,notPick,rem});
    // }
    
    int HelperMemoized(vector<string>&strs ,int one ,int zero , int& maxZero , int& maxOne ,int i)
    {
        // m => 0 , n => 1
        // Here one and zero are changing
        // base case 
        if(i>=strs.size())
        {
            return 0;
        }


        if(one > maxOne or zero > maxZero)
            return 0;


        if(dp[i][one][zero]!= -1)
        {
            return dp[i][one][zero];
        }

        // check -->
        pair<int, int> p = countOnesZeros(strs[i]);
           
        int pick = 0, notPick = 0, rem = 0;
        if( one + p.first <= maxOne && zero + p.second <= maxZero )
        {
            // you can choose that element or dont choose that element 

            // choose 
            pick = 1 + HelperMemoized(strs, one + p.first, zero + p.second, maxZero, maxOne, i+1);
            // dont choose
            notPick = HelperMemoized(strs, one, zero, maxZero, maxOne, i+1);
            return dp[i][one][zero] = max(pick,notPick);
        }
        else
        {
           return dp[i][one][zero] = HelperMemoized(strs,one,zero,maxZero,maxOne,i+1);

        } 

        return dp[i][one][zero] ; //finally return the last element --> that means the size of the largest subset. 
    }


    int findMaxForm(vector<string>& strs, int m, int n)
    {
        // m --> 0 and n--> 1
        memset(dp, -1, sizeof(dp));

        // in a vector store zero and one count of each element 
        int maxZero = m;
        int maxOne = n;
        // return Helper(strs,0,0,maxZero,maxOne,0);
        return HelperMemoized(strs,0,0,maxZero,maxOne,0);
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