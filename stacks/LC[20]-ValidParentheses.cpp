#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {

        // Example : "{ [ ( ) ] }"

        // make a stack 
        stack<char> stk;

        for(int i=0;i<s.length();i++)
        {
            // intuition : whenever you hit openning bracket put in the stack 
            if((s[i]=='(') || (s[i]=='{') || (s[i] == '['))
            {
                //push in the stack 
                stk.push(s[i]);
            }
            else
            {
                // incase of closing bracket 
               
               // case:  when you encounter closing bracket first then stack will remain empty 
               if (stk.empty()) return false;
                
                // compare 
                // top element of the stack with current closing bracket , if they make pair then pop the element from stack
                char c = stk.top(); 
                
                if( (s[i]==')' and c == '(' ) || (s[i]== ']' and c == '[' ) || (s[i]== '}' and c == '{' ))
                {
                    stk.pop();
                    // continue;
                }
                else
                {
                    // mismatch 
                    return false;
                }

            }
        }

        // finally , if stack is empty then true 
        if(stk.empty()) return true;

        return false;
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