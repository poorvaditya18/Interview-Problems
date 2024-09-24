#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
private:
    string replace_char_by_number(string &s)
    {
        string res ="";
        for(auto ch:s)
        {
            res += to_string(ch - 'a' + 1);
        }
        return res;
    }

    int transform_string(string res, int k)
    {
        while(k>0)
        {
            int sum = 0;
            for(int i=0;i<res.size();i++)
            {
                int num = res[i]-'0';
                sum += num;
            }
            res = to_string(sum);
            k--;
        }
        return stoi(res);
    }
public:
    int getLucky(string s, int k) 
    {
        // replace characters by number
        int result=0; 
        string numberString;
        numberString = replace_char_by_number(s);
        result = transform_string(numberString,k);
        
        return result;
    }
};

int main()
{
    Solution s;
    cout<<s.getLucky("iiii",1);
    return 0;
}