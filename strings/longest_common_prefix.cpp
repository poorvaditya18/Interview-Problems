#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string ""
 */

class Solution{	
	public:
        static bool custom_comparator(string &a, string &b)
        {
           return a < b;
        }
        
		string longestCommonPrefix(vector<string>& str)
		{
            // arr[] = ["flowers" , "flow" , "fly", "flight" ]
            string common_prefix = "";
            
            // sort this will sort string lexicographically
            sort(str.begin(), str.end(), custom_comparator);
            
            for(auto ele:str)
            {
                cout<<ele<<" ";
            }
            cout<<endl;
			// ["flight" , "flow" , "flowers", "fly" ]  

            int idx = 0;
            string first_string = str[0];
            string last_string = str[str.size()-1];

            int minLen = min(first_string.size(), last_string.size());

            while(idx < minLen)
            {
                if(first_string[idx]!= last_string[idx]) break;
                idx++;
            }

            common_prefix = first_string.substr(0, idx);

            return common_prefix;
		}
};



int main()
{
    Solution s;
    vector<string> str{"flowers" , "flow" , "fly", "flight"};
    cout<<s.longestCommonPrefix(str);
    return 0;
}