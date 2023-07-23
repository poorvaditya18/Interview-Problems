#include<bits/stdc++.h>
using namespace std;


bool goodEnough(int mid ,int n ,int x ,int y)
{
		// now int mid time how many copies can be generated ?
		int countCopies = (mid/x)+ (mid/y);
		return countCopies>=(n-1);
}


int VeryEasyTaskFunc(int n,int x,int y)
{
	if(n==1)
	{
		// whichever copier takes less time 
		return min(x,y);
	}
	// otherwise -->
	// so n -> copies we need to produce 
	// we have two copiers -> with speed x and speed y 
	// both copiers can work parallely.
	// Intuition ->
	// deciding the search space . Basically , making search space of minimum Time 
	// when n= 0 means no copies to produce so minimum time it will take 0 sec
	// maximum time that it can take will be --> max(x,y)
	int low = 0;
	int high = max(x,y)*n;
	int ans=-1;
	while(low<=high)
	{
		int mid = low +(high - low)/2;

		// now check whether this mid(time) is good or not to produce n copies 
		if(goodEnough(mid,n,x,y))
		{
			// then we need to search for the minimum optimal answer
			ans = mid;
			high = mid-1;
		}
		else
		{
			low = mid+1;
		}
	}
return ans+ min(x,y);
}


int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
	int n,x,y;
	cin>>n>>x>>y;
	cout<<VeryEasyTaskFunc(n,x,y)<<endl;
 
	return 0;

}