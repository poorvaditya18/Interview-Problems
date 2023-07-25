#include<bits/stdc++.h>
using namespace std;


// Power Function -> calculate a ^ b = a * a^ (b-1)
int PowerFunc(int a, int b)
{
	// base case 
	if(b==0)
	{
		return 1; // as a ^ 0 = 1
	}

	// recursive call 
	return a*PowerFunc(a,b-1);
}



int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
	int a = 2,b=3;
	cout<<PowerFunc(a,b)<<endl;
 
	return 0;

}