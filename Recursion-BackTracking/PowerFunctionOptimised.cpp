#include<bits/stdc++.h>
using namespace std;


// Power Optimised 

// Now here we will optimised Power 
int PowerFuncOptimised(int a , int b)
{
	if(b==0)
	{
		return 1;
	}

	int value = PowerFuncOptimised(a,b/2);
	// check for odd or even 
	if(b%2==0)
	{
		//even
		return value*value;
	}
	else
	{
		return a*value*value;
	}

}

int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
	int a,b;
	cin>>a>>b;
	cout<<PowerFuncOptimised(a,b)<<endl;
 
	return 0;

}