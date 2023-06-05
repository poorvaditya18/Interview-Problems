#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        // sliding window optimisation -->
        // using hashmap 
        unordered_map<char,int> mpp; // will store char , index+1 

        int l = s.length(); // size of string 

        int i =0;
        int j =0;

        // window = i-j+1 , any time window will store unique elements
        int ans = 0;
        for(int i=0;i<l && j<l;j++)
        {
            char st = s[j];
            int currIdx = j;
            if(mpp.find(st)!=mpp.end())
            {
                    // present
                    // move i to the newidx
                    i = max(mpp[st],i);
                    // update the value of the oldIdx
                      
            }
                // not present 
                mpp[st] = currIdx + 1;
                ans = max(ans,j-i+1);

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