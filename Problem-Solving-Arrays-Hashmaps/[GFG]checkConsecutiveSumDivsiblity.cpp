#include<bits/stdc++.h>
using namespace std;
 

 //  GFG - question to check whether three consecutive elements sum is divisible by 10 or not , if divisible then return true. 
// Intuition - sliding window 


int check(int n , vector<int> &a)
{
	if(n==0) return 0; 

	// sliding window 
	int i=0;
	int j=0;

	int k = 3; // window size given 

	int sum = 0;

	while(j<n)
	{
		sum += a[j];
		if(j-i+1<k)
		{
			j++;
		}
		else if(j-i+1==k)
		{
			// check condition 
			if(sum%10==0) 
				{
					
					return 1;
				}

			else
			{
				sum -= a[i];
			i++;
			j++;
			}
			
		}
	}

return 0;

}

int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
	vector<int> arr = {10,11,21,8};
	cout<<check(4,arr);


	return 0;

}