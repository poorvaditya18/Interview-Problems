#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int index;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(mid==0)
            {
                return high;
            }
            if(mid==n-1)
            {
                return low;
            }
            if((arr[mid]>arr[mid-1]) and (arr[mid]>arr[mid+1]) )
            {
                    return mid;
            }
            else if(arr[mid]<arr[mid+1])
            {
                low= mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return -1;
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