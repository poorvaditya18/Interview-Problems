#include<bits/stdc++.h>
using namespace std;


vector<int> twoSum(vector<int> nums,int target)
{

			 map<int,int> mpp; // will store element and its array index

	        for(int i=0;i<nums.size();i++)
	        {   
	            int currIdx = i;
	            int ele = target - nums[i];

	            if(mpp.find(ele)!=mpp.end())
	            {
	                // element present 
	                int idx = mpp[ele];
	                return {i,idx};
	            }

	            
	            mpp[nums[i]]=currIdx;
	        }
	        return {-1,-1};
}


int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
 
	return 0;

}