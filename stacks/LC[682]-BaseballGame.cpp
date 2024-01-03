#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {


      // will store points  
      stack<int> record;

      for(int i=0;i<operations.size();i++)
      {
        
        // if stack is empty 
        if(record.empty())
        {
            record.push(stoi(operations[i]));
        }
        else
        {
            if(operations[i] == "+")
            {
                        int x = record.top(); 
                        record.pop();
                        int y = record.top(); 
                        record.push(x); 
                        record.push(x+y);
            }
            else if(operations[i]=="C")
            {
                record.pop();
            }
            else if (operations[i]=="D")
            {
                record.push(2*record.top());
            }
            else
            {
                // convert to int and push 
                record.push(stoi(operations[i]));
            }
        }

      }


        int sum = 0;
        while(!record.empty())
        {
            sum += record.top();
            record.pop(); 
        }

        return sum;
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