#include<bits/stdc++.h>
using namespace std;

class Solution 
{

public:
    vector<int> ans;

     void helper(vector<int>&arr,int i,int N,int sum)
     {
        if(i==N)
        {
            ans.push_back(sum);
            return;
        }
        helper(arr,i+1,N,sum+arr[i]);
        helper(arr,i+1,N,sum);
     }
    vector<int> subsetSum(vector<int>&arr,int N)
    {
        int sum=0;
        helper(arr,0,N,sum);
        return ans;
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