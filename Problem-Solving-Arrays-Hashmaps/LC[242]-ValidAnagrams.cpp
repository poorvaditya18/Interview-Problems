#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        // different length 
        if(s.length()!=t.length()) return false;

        // same length 
        // check for characters 

        unordered_map<char,int> mpp;// char and frequency 
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(auto ele:s)
        {
            if(mpp.find(ele)!=mpp.end())
            {
                mpp[ele]++;
            }
            else
            {
                mpp[ele]++;
            }
        }

        for(auto t_ele: t)
        {
            if(mpp.find(t_ele)!=mpp.end())
            {
                // element present 
                // decrease the frequency 
                mpp[t_ele]--;
            }
            else if(mpp.find(t_ele)==mpp.end())
            {
                return false;
            }
        }
        for(auto ele:mpp)
        {
            if(ele.second>0) return false;
        }
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