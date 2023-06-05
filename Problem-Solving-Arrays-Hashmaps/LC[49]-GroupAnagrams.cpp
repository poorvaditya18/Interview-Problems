#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
         vector<vector<string>>  ans;
         if(strs.size()==0) return ans;
            // Intuition -> sort and check if equal then anagrams . 
         
         unordered_map<string,vector<string>> mpp;

         for(auto s:strs)
         {
             string sortedStr = s;
             // sort the string 
             sort(sortedStr.begin(),sortedStr.end());

             // check whether it is there in the map or not
             if(mpp.find(sortedStr)==mpp.end())
             {
                 // means not present 
                 // add it 
                 mpp[sortedStr] = vector<string>();
             }

             // add the original string i.e without the sorted  
             mpp[sortedStr].push_back(s);
         }

        // copy the array 
        for(auto vi:mpp)
         {
             ans.push_back(vi.second);
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