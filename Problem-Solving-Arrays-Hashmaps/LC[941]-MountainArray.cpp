#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool validMountainArray(vector<int>& arr) 
 {
        if(arr.size()<3) return false;
        // >= 3
        int sz = arr.size();
        int peakIdx=0;
        // find peak index -> while moving up 

        int j=0;
        while(j+1<sz && arr[j]<arr[j+1])
        {
            j++;
        }
       
        // check whether the peak idx is in the starting or not 
        peakIdx = j;
        if(peakIdx==0 or peakIdx == sz-1) return false;

        // check while going down 
        while(j+1<sz && arr[j]>arr[j+1])
        {
            j++;
        }

        // return true when j becomes equal to sz-1, 
        
        return j==sz-1;
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