#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkPossibility(vector<int>& nums) 
    {
        // single element always increasing 
        if(nums.size()==1) return true;


        bool changed = false;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            // if true  i.e till now array is in increasing order 
            if(nums[i]<=nums[i+1])
            {
                continue;
            }

            // then first check any other element is changed or not 
            // if changed then return false; as you can only modify one element .
            if(changed) return false;

            // modify the element 
            else
            {
                // if not then change the element 
                if (i==0 or nums[i+1]>=nums[i-1])
                {
                    // change the left element i.e ith 
                    nums[i] = nums[i+1];
                }
                else
                {
                    // change the right element i.e i+1 
                    nums[i+1] = nums[i];
                }
                changed = true;
            }
            
        }
        
        return true; // that means array is in non decreasing order . 
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