#include<bits/stdc++.h>
using namespace std;


int SumRecurSive(int num)
{
	// base case 
	if(num==0)
	{
		return 0;
	}
	return SumRecurSive(num/10) + (num%10);
}

int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
	int num=1234;
	cout<<SumRecurSive(num)<<endl;
 
	return 0;

}