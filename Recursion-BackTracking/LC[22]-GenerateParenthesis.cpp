#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    vector<string> ans;

    void generateHelper(int n , int openningBracket, int closingBracket,string output)
    {
        // base case 
        // (()) --> in this case closing will be equal to n
        if(closingBracket==n)
        {
            ans.push_back(output);
            return ;
        }
        
        // (( --> then still closing can be added 
        if(openningBracket > closingBracket)
        {
            // you can still add closing parenthesis
            generateHelper(n,openningBracket,closingBracket+1,output+")");
        }

        // n=2 (-> then opening bracket can be added
       if(openningBracket < n)
       {
           // you can still add opening parenthesis
           generateHelper(n,openningBracket+1,closingBracket,output+"(");
       }

    }


    vector<string> generateParenthesis(int n) 
    {
        ans.clear();
        generateHelper(n,0,0,"");
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