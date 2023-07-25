#include<bits/stdc++.h>
using namespace std;


// fibonacci using recursion 
int f(int n)
{
	if(n==0 or n==1) return n;

	return f(n-1)*f(n-2);

}



int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
 
	return 0;

}