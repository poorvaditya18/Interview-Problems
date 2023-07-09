#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {

        map<char,char> mp1; //mapping for s 
        map<char,char> mp2; //mapping for t

        for(int i=0;i<s.size();i++)
        {
           // check mapping for both s and t 

           if(mp1.find(s[i])==mp1.end() and mp2.find(t[i])==mp2.end())
           {
             // not present in both then add 
             mp1[s[i]]=t[i];
             mp2[t[i]]=s[i];
           }
           else
           {
           		// if in any case value gets differed then return false;
               if(mp1[s[i]]!=t[i] || mp2[t[i]]!=s[i])
               {
                   return false;
               }
           }

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