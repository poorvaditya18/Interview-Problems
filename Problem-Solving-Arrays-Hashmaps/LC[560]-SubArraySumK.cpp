#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {

        unordered_map<int,int> mpp; // will store sum[i] and no of occurence of sum[i] 
       int sum =0;
       int count = 0;
       mpp.insert({0,1}); // by default 

       for(int i=0;i<nums.size();i++)
       {
           //ith sum 
           sum+=nums[i];

           // check sum -k is present or not 
           if(mpp.find(sum-k)!=mpp.end())
           {
               // sum is present 
               count+=mpp[sum-k];
           }
           mpp[sum]++;
       }
       return count;
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