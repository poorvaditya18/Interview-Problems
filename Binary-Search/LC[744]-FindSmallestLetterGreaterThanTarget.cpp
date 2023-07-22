#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        // condition --> array is sorted (Binary Search)
        int n = letters.size();
        int low = 0;
        int high = n-1;
        char result;
        bool found = false;
        while(low<=high)
        {
            int mid = low +(high-low)/2;
            
            // case 1:  
            if((letters[mid])>(target))
            {
                result = letters[mid];
                high=mid-1;
                found = true;
            }
            // case 2:
            else
            {
                low = mid+1;
            }
        }
        if(found)
        {
            return result;
        }
        return letters[0];
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