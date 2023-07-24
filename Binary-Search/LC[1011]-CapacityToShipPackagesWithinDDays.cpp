#include<bits/stdc++.h>
using namespace std;
// 1011. Capacity To Ship Packages Within D Days
class Solution {
public:

    bool goodFunc(vector<int>&weights,int mid,int days)
    {
        int sum=0;
        int DaysTillNow = 1;
        for(int i=0;i<weights.size();i++)
        {
            if(weights[i]>mid)
            {
                return false;
            }
            if(sum+weights[i]>mid)
            {
                DaysTillNow++;
                sum = weights[i];
                if(DaysTillNow > days)
                {
                    return false;
                }
            }
            else
            {
                sum+=weights[i];
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {

      // maximum = sum 
      // minimum = 1
      int ans =-1;
      int sum =0;
      for(int i=0;i<weights.size();i++)
      {
         sum += weights[i];
      }
        int low = *min_element(begin(weights),end(weights)); // minimum capacity of the ship 
        int high = sum; // maximum capacity of the ship 
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            // mid represent -> capacity that can result in all packages shipped within days
            if(goodFunc(weights,mid,days))
            {
                ans = mid ;
                high = mid-1;
            }
            else
            {
                low = mid +1;
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