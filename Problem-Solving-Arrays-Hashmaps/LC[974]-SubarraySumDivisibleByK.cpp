#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        // using hashmap 
        unordered_map<int,int> mpp; // will store remainder and its count 

        int PrefixSum=0;
        int count =0;
        mpp.insert({0,1});
        for(int i=0;i<nums.size();i++)
        {
            PrefixSum+=nums[i];
            int rem = ((PrefixSum%k)+k)%k ;
            // check whether remainder is present in map or not 
            if(mpp.find(rem)!=mpp.end())
            {
                // remainder is present 
                // first add its previous count 
                count+=mpp[rem];  
            }
             mpp[rem]++;
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