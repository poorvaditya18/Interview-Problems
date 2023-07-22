#include<bits/stdc++.h>
using namespace std;


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        if(n==1) return 1;
        int low =1;
        int high =n;
        int result = INT_MAX;
        while(low<=high)
        {
            int mid= low +(high-low)/2;
            if(isBadVersion(mid))
            {
                result = min(result,mid);
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return result;
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