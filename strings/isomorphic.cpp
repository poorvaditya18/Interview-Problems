#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution
{
    public:

    bool isomorphicString(string &s, string &goal) 
    {
    	    if(s==goal) return true;
            int i,j;
			for(i=1;i<s.size();i++)
			{
				// rotate
				char ch = s[0];
				for(j=1; j<s.size(); j++)
				{
					s[j-1] = s[j]; 
				}
				// update last element 
				s[j-1] = ch;
				if(s==goal) return true;
			}

			if(i==s.size()) return false;

			return true;
    }

};

int main()
{
    Solution s;
    string s1, s2;
    cin>>s1>>s2;
    s.isomorphicString(s1, s2);
    return 0;
}