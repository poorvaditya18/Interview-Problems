#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int n = bloomDay.size();
        if(1ll*m*k > 1ll*n) return -1; // edge case
       // Intuition --> 
       // if m=0 i.e no bouquet needed, then minimum days will be 0 
       // since we want minimum number of days -->
       // we will make our search space in terms of days
       // minimum no of days required => smallest bloomDay
       // maximum no of days required => greatest bloomDay
      
       int low = *min_element(begin(bloomDay),end(bloomDay));
        int high = *max_element(begin(bloomDay),end(bloomDay));
        int ans=-1;
       while(low<=high)
       {
           int mid = low + (high-low)/2;
           // check whether this mid (that is number of day is goodEnough 
           // to make m bouquets using k adjacent flower or not)
           if(goodEnough(bloomDay,mid,m,k))
           {
               // this can be potential answer
               ans = mid;
               // search further for minimum number of day
               high = mid-1;
           }
           else
           {
               low = mid+1;
           }
       }
       return ans;
    }

    bool goodEnough(vector<int>&bloomDay,int mid,int m,int k)
    {
        // now if mid > flower's bloomDay --> means  it have bloomDay before mid.
        int flowerBloomed = 0;
        int expectedCountOfBouquet =0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(mid>=bloomDay[i])
            {
                flowerBloomed++;
            }
            else
            {
                //here : you have found the flower that have not bloomed
                // since 1 bouquet will take k flowers 
                // so with flower that have Bloomed you will be able to make flowerBloomed/k bouquets
                expectedCountOfBouquet += flowerBloomed/k;
                // since we want adjacent again make the flowerBloomed = 0;
                flowerBloomed = 0;
            }
        }
        // again check 
        expectedCountOfBouquet += flowerBloomed/k;
        return expectedCountOfBouquet>=m;
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