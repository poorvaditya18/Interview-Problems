#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
       map<int,int> mpp;
       vector<int> ans;
       for(auto ele:nums)
       {
           if(mpp.find(ele)!=mpp.end())
           {
              mpp[ele]++;
           }
           else
           {
               mpp.insert({ele,1});
           }
       }
       for(int i=1;i<=nums.size();i++)
       {
           if(mpp.find(i)!=mpp.end())
           {
               continue;
           }
           else
           {
               ans.push_back(i);
           }
       }
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