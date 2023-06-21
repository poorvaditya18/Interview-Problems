#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) 
    {
        // sliding window approach 
        int n = nums.size();
        vector<int>ans(n,-1); // initialise vector w -1 
        int i=0;
        int j=0;
        long long int sum = 0;
        int windowSize = 2*k+1;
        while(j<n)
        {
            sum+=nums[j];
            if(j-i+1<windowSize)
            {
                j++;
            }
            else if(j-i+1==windowSize)
            {
                // store the average at the particular index
                ans[j-k]= sum/(windowSize);
                sum-=nums[i];
                i++;
                j++;
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