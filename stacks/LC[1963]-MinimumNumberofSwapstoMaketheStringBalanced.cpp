#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minSwaps(string s) 
    {

        // since [] -> will have count as 0 as already balanced.

        // idea -> stack will store the unbalanced open brackets that need to swapped
        // since each swap balances 2 
        // therefore max swaps = 1/2(no of open brackets)

        stack<char> stck;
        int res =0;

        for(int i=0;i<s.length();i++)
        {
            // if it is openning bracket then push it stack 
            if(s[i]=='[')
            {
                stck.push(s[i]);
            }
            else
            {
                // for closing bracket 
                // check whether there is a closing bracket at top 
                if(!stck.empty() && stck.top()=='[')
                {
                    stck.pop();
                }
            }
        }


        // check size 
        // since each swap balance 2 
        res = stck.size();

        if(res%2==0)
        {
            return res/2;
        }
        return (res+1)/2;

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