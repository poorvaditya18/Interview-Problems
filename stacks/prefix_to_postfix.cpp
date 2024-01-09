#include<bits/stdc++.h>
using namespace std;

bool isOperand(char c)
{
	if((c>='a' && c<='z') or (c>='A' && c<='Z') or (c>='0' && c<='9')) return true;
	// else it is not a operand 
	return false;
}

// prefix to postfix 

string prefix_to_postfix(string prefix_str)
{

	// 1. reverse  prefix str
	reverse(prefix_str.begin(),prefix_str.end());


	// here in the stck now we will push operands
	stack<string> stck;

	for(int i=0;i<prefix_str.length();i++)
	{
		char current_character = prefix_str[i];

		if(isOperand(current_character))
		{
			stck.push(string(1,prefix_str[i]));
		}
		else
		{
			// operator 
			// take out operand 1 and operand 2 
			// pop two operands from stack
            string op1 = stck.top();
            stck.pop();
            string op2 = stck.top();
            stck.pop();
 
            // concat the operands and operator
            string temp = op1 + op2 + prefix_str[i];
 
            // Push string temp back to stack
            stck.push(temp);
		}

	}
	return stck.top();

}


int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	

	string pre_exp = "*-A/BC-/AKL";
    cout << "Postfix : " << prefix_to_postfix(pre_exp);
	
 
	return 0;

}