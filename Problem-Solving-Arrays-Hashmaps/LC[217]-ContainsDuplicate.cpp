#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto ele:nums)
        {
            mpp[ele]++;
        }
        for(auto ele:mpp)
        {
            if(ele.second>1) return true;
        }
        return false;
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