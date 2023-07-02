#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<string> mapper = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> res;
    void func(string &str,int i, string output)
    {
        // base case --> if i equals to string size
        if(i==str.size())
        {
            // push the result 
            res.push_back(output);
            return;
        }

        // get the digit 
        int digit = str[i]-'0';
        // get the mapping string 
        string charsOfMapping = mapper[digit];

        // iterate over mapping string 
        for(int j=0;j<charsOfMapping.size();j++)
        {
            // assume it will give correct answer for i+1 and then append the current character
            // for all possible combinations
            func(str,i+1,output+charsOfMapping[j]);
        }
        
    }

    vector<string> letterCombinations(string digits) {
        res.clear();
        if(digits.size()==0)
        {
            return res;
        }
        func(digits,0,"");
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