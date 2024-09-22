#include<iostream>
#include<string>
using namespace std;

class Solution{	
	public:
		bool rotateString(string& s,string& goal)
		{
			//your code goes here
			// abcde
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