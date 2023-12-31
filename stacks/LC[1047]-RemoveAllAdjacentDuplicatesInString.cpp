#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string removeDuplicates(string s) {

        // make a stack st1 and st2  of characters
        stack<char> st1;
        string ans;

        for(int i=0;i<s.length();i++)
        {

            if(!st1.empty())
            {
                // comparision
                char s1 = st1.top();
                if(s1==s[i])
                {
                    // remove top element 
                    st1.pop();
                }
                else
                {
                    // push element to stack 
                    st1.push(s[i]);
                }
            }
            else
            {
                st1.push(s[i]);
            }

        }

        while(!st1.empty())
        {
            ans += st1.top();
            st1.pop();
        }

        // reverse the string to get final answer
        reverse(ans.begin(), ans.end());

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