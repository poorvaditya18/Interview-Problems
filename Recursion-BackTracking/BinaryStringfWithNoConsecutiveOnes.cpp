#include<bits/stdc++.h>
using namespace std;

int BinaryStrings(int num)
{
	// base case 
	if(num==1)
	{
		return 2;
	}
	if(num==2)
	{
		return 3;
	}
	return BinaryStrings(num-1)+ BinaryStrings(num-2);
}

int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
	int num = 5;
	cout<<BinaryStrings(num)<<endl;
 
	return 0;

}