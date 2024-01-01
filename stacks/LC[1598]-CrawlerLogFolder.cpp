#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) 
    {
        stack<string> stck;

        for(int i=0 ; i < logs.size();i++)
        {
            if(logs[i]== "../")
            {
                // pop the top element
                if(!stck.empty())
                {
                    stck.pop();
                }
                
            }
            else if (logs[i]== "./")
            {
                continue;
            }
            else
            {
                stck.push(logs[i]);
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