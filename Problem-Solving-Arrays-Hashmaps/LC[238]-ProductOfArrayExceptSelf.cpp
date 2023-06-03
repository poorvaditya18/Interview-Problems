#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> productExceptSelf(vector<int>& nums) 
    {

    	// Time Complexity --> O(n)
    	// Space Complexity --> O(2n)= O(n)

        int n = nums.size();
        vector<int> left_prod(n);
        vector<int> right_prod(n);
        vector<int> ans(n);

        left_prod[0] =1 ; 
        right_prod[n-1]= 1;
        // fill left product array-->
        for(int i=1;i<nums.size();i++)
        {
            left_prod[i]=nums[i-1]*left_prod[i-1];
        }

        // fill right product array -->
        for(int i=n-2;i>=0;i--)
        {
            right_prod[i] = nums[i+1]*right_prod[i+1] ;
        }

        // for every element take lprod(i)*rprod(i)   
        for(int i=0;i<nums.size();i++)
        {
            ans[i] = left_prod[i]*right_prod[i];
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