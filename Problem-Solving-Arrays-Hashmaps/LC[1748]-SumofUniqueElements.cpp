#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int sumOfUnique(vector<int>& nums) 
    {
        unordered_map<int,int> mpp;
        int sum =0;
        for(auto ele:nums)
        {
            mpp[ele]++;
        }
        for(auto ele:mpp)
        {
            if(ele.second==1)
            {
                sum+=ele.first;
            }
        }
        return sum ;
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