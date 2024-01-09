#include<bits/stdc++.h>
using namespace std;


// infix to post fix conversion 


int check_operator_precendence(char c)
{
	if(c == '^') return 3;
	else if(c=='*' or c=='/') return 2;
	else if(c=='+' or c=='-') return 1;
	else return 0;
		
}

bool isOperand(char c)
{
	if((c>='a' && c<='z') or (c>='A' && c<='Z') or (c>='0' && c<='9')) return true;
	// else it is not a operand 
	return false;
}

// convert infix to postfix 

// string exp = "A + B * C + D";
//  stack = [, ]

string infix_to_postfix(string s)
{
	// algorithm

	// 1. if it is a operand --> add to the result string 
	// 2. if it is a operator and stck is empty then --> push it in the stack .
	// 3. if it is a operator and stck is non empty :
	// 		3a. check operator precendence : if current operator have lesser precendence than top of the stack then it will be not be pushed directly.  or we can say stck top operator have higer or equal precendence then current operator we can't push the element. 
	//										 so we will pop out till stck is not empty. or we encounter operator of lesser precendence. 
	// 										 we can only push the operator if it have greater precendence then stck.top()

	stack<char> stck; 
	string result;

	for(int i=0;i<s.length();i++)
	{
		// check whether element is a operand or not 
		char current_character= s[i];
		// cout<<current_operator<<endl;

		if(isOperand(current_character))
		{
			result+=s[i];
		}
		else if(current_character =='(')
		{
					stck.push(s[i]);
		}	
		else if(current_character ==')')
		{
					while(stck.top()!= '(')
					{
						result+=stck.top();
						stck.pop();
					}
					stck.pop();
		}
		else
		{
					// current operator have lesser or equal precendence than top() --> pop till stck become empty or you encounter operator of higer precendence
					// you cant push directly 
					// we need to pop the operators 
					while( ( !stck.empty() and (check_operator_precendence(s[i]) < check_operator_precendence(stck.top()) ) ) or ( !stck.empty() and ( check_operator_precendence(s[i]) == check_operator_precendence(stck.top()) ) )  ) 
					{
						result+=stck.top();
						stck.pop();
					}
					// push the current operator 
					stck.push(s[i]);
		}
		
	}
	
	while(!stck.empty())
	{
		result+=stck.top();
		stck.pop();
	}
	return result;
}



int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
 	// string exp = "A+B*C+D";
	string exp = "((A+B)-C*(D/E))+F";

	cout<<infix_to_postfix(exp)<<endl;
	return 0;

}