#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    class Solution {
public:
    string simplifyPath(string path) 
    {
        
        stack<string> st;

        string res;

        for(int i=0;i<path.length();i++)
        {
            if(path[i]=='/')
                continue;
            
            string temp;

            while(i<path.length() && path[i]!='/')
            {
                // store it in temp
                temp += path[i];
                ++i;   
            }


            // check temp 
            if (temp == ".")
            {
                continue;
            }
            else if (temp == "..")
            {
                // check stack is empty or not 
                if(!st.empty())
                {
                    // pop the element
                    st.pop();
                }
            }
            else
            {
                // else push 
                st.push(temp);
            }
        }

        // finally stack will have all canonical path
        // add "/"
        while(!st.empty())
        {
            res = "/" + st.top() + res;
            st.pop();
        }

        if(res.size()==0) return "/";

        return res;
    }
};
};



int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
	Solution s_obj;

	string path = "/home/";

	string ans = s_obj.simplifyPath(path) ;

	cout<<ans<<endl;
 	
	return 0;

}