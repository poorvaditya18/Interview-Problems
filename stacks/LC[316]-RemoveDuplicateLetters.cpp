#include<bits/stdc++.h>
using namespace std;

// similar to Question : https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/submissions/



class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        string res;

        // set --> to store the element seen so far 
        set<char> st;

        // map --> to store last_occurence of strings  
        map<char,int> mpp;

        // stack --> to store keep track of letters , finally stack will have  lexicographically smalles string 
        stack<char> stk;

        // store the last_occcurence of elements
        for(int i=0;i<s.length();i++)
        {
            mpp[s[i]] = i;
        }


        for(int i=0;i<s.length();i++)
        {
            char c = s[i];

            // That means element is not seen 
            // if already seen means it was taken in the output eariler 
            if(st.find(c)== st.end())
            {
                // case: 

                // check whether stack is not empty 
                // current character is < stack top 
                // top character will  again occur further in string 
                while(! stk.empty() && c < stk.top() && mpp[stk.top()]>i)
                {
                    // then pop top 
                    // value from seen and stack.
                    char t = stk.top();
                    st.erase(t);
                    stk.pop();
                }
 
                stk.push(c); // push current character
                st.insert(c); // mark it as seen 
            }
        }

        while(!stk.empty())
        {
            res+= stk.top();
            stk.pop();
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