#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string makeGood(string s) {
        
        stack<char> stck;
        string res;

        for (int i=0;i<s.length();i++)
        {
            if(!stck.empty())
            {
                // check whether elements are equal or not 
                char ele = stck.top();
                if(ele-'A' == s[i]-'a' || ele -'a' == s[i]-'A')
                {
                    stck.pop();
                    continue;
                }
            }
            stck.push(s[i]);
        }

        while(!stck.empty())
        {
            res += stck.top();
            stck.pop();
        }


        reverse(res.begin(),res.end());

        return res;

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