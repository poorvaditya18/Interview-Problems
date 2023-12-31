#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int scoreOfParentheses(string s) {
     
        stack<int> stk; // to have the record of "(" 

        for(int i=0;i<s.length();i++)
        {
            if(s[i]== '(')
            {
                // if it is openning bracket 
                // then we will push -1 in stack
                stk.push(-1);
            }
            else
            {
                // it is a closing bracket

                // case : () ---> then top is -1 --> score = 1
                if(stk.top()==-1)
                {
                    // pop -1 
                    stk.pop(); 
                    // push complete score as 1 
                    stk.push(1);
                }
                // case : can be either  ( A ) or ( A + B )
                else
                {
                    // add scores till you reach "(" i.e -1
                    int val = 0;
                    // since we have balanced parenthesis , stack will not become empty 
                    while(stk.top()!=-1)
                    {
                        val = val + stk.top();
                        stk.pop();
                    }

                    // remove last openning bracket
                    stk.pop();
                    stk.push(2*val);
                }
            }
        }

        // finally add all the scores
        // because there might be case of ()() ==>  1+1 = 2
        int ans = 0;
        while(stk.size()>0)
        {
            ans = ans + stk.top();
            stk.pop();
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