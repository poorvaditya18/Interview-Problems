#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minLength(string s) 
    {

        stack<char> stck;

        for(int i=0;i<s.length();i++)
        {
            // before pushing check what element is there at top of the stack 
            if(!stck.empty())
            {
                char ele = stck.top();
                if( (ele == 'A' and s[i]== 'B') or (ele == 'C' and s[i]== 'D'))
                {
                    stck.pop();
                }
                else
                {
                    stck.push(s[i]);
                }
            }
            else
            {
                stck.push(s[i]);
            }
        }
        return stck.size();
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