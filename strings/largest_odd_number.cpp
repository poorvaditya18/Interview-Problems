#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{	
public:	

    string largeOddNum(string& s)
    {
        //your code goes here
        string str ;

        int idx;
        for(int i=s.size()-1;i>=0;i--)
        {
            if((s[i]-'0')%2!=0)
            {
                //means odd number;
                idx=i;
                break;
            }
        }

        // remove leading zeroes
        int i=0;
        while(s[i]=='0')
        {
            i++;
        }

        // window size = j-i+1;
        // i = 2, j = 7
        str = s.substr(i,idx-i+1);
        return str;
    }
};

int main()
{
    /*
    Input : s = "0214638"
    Output : "21463"

    Explanation : The different odd numbers that can be formed by the given string are --> 1, 3, 21, 63, 463, 1463, 21463.

    We cannot include 021463 as the number contains leading zero.

    So largest odd number in given string is 21463.
    */
    Solution s;
    string str, res;
    cin>>str;
    res= s.largeOddNum(str);
    cout<<res;
    return 0;
}