#include<bits/stdc++.h>
using namespace std;


// Smallest Positive Missing Positive Integer -->
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int n = nums.size();
        bool containsOne = false;

        // check whether 1 is there or not , if not then 1 is answer
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                containsOne = true;
                break;
            }
        }

        // means 1 is not present 
        if(containsOne==false)
        {
            return 1;
        }

        // do data clean up 
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=0 or nums[i]>n)
            {
                // make them  as 1
                nums[i] = 1;
            }
        }

        // using hashing concept ->
        for(int i=0;i<n;i++)
        {
            // if any element is negative , make it as positive first 
            int Idx = abs(nums[i]);

            if(Idx==n)
            {
                // mark 0th index as negative
                nums[0] = -1*abs(nums[0]);
            }
            else
            {
                nums[Idx]= -1*abs(nums[Idx]);
            }
        }

        // start from 1 idx -->
        for(int i=1;i<n;i++)
        {
            if(nums[i]>0)
            {
                return i;
            }
        }

        
        // finally check for 0th index means n was the missing number 
        if(nums[0]>0)
        {
            return n;
        }

        return n+1; // maximum possible missing positive number 

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