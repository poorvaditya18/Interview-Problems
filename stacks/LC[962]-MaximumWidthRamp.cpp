#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxWidthRamp(vector<int>& nums) 
    {
        
        // make a decreasing stack 

        stack<int> stck;
        int maxi = 0;

        for(int i=0;i<nums.size();i++)
        {
            if(stck.empty() or nums[stck.top()] > nums[i])
            {
                stck.push(i);//push index of element
            }
        }

        for(int i=nums.size()-1;i>=0;i--)
        {
            // now check from last 
            while(!stck.empty() && nums[i] >= nums[stck.top()])
            {
                maxi= max(maxi , i - stck.top());
                stck.pop();
            }
        }
        return maxi;
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