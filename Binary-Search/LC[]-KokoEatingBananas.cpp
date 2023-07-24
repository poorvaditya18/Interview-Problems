#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {

        int low = 1;
        int high = *max_element(begin(piles),end(piles));
        int ans=-1;
        while(low<=high)
        {
            int mid = low +(high-low)/2;
            // check mid is good enough to eat all bananas or not 
            if(goodEnough(piles,mid,h))
            {
                // then it can be potential answer
                ans = mid;
                // check for minimum 
                high = mid-1;
            }
            else
            {
                // look for higher k 
                low= mid+1;
            }
        }
        return ans;
    }
    bool goodEnough(vector<int>&piles,double mid,int h)
    {
  
   // integer mid 
   // whether for this "mid" Koko can eat all bananas within h hours 
   long long  hours =0;
   for(int i=0;i<piles.size();i++)
   {
       hours+=ceil(piles[i]/mid);
   }
    if(hours>h) return false;
    return true;
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