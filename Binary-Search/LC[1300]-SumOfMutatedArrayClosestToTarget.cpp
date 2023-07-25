#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) 
    {
        int low =0;
    
        int maxi=-1;
        int ans=-1;
        for(int i=0;i<arr.size();i++)
        {
            maxi=max(maxi,arr[i]);
        }
        int high = maxi;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int CurrSum = goodFunc(arr,mid);
            if(CurrSum ==mid)
            {
                return mid;
            }
            if(CurrSum>target)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        // now when low > high 
        // check again for low , low-1
        if(abs(target-goodFunc(arr,low-1))>abs(target-goodFunc(arr,low)))
        {
            return low;
        }
        return low-1;
    }
    int goodFunc(vector<int>&arr,int mid)
    {
        int currSum =0;
        for(int i=0;i<arr.size();i++)
        {
           if(arr[i]>mid)
           {
               currSum+=mid;
           }
           else
           {
               currSum+=arr[i];
           }
        }
        return currSum;
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