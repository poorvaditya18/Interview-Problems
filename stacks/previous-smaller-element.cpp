#include<bits/stdc++.h>
using namespace std;

// previous smaller element 


// 30 12 40 20 2 4 10 
// -1 -1 12 12 -1 2 2 


// 10 4 2 20 40 12 30 
// 4  2 -1 12 12 -1 -1 
vector<int> nse(vector<int>&arr)
{

	stack<int> stck;

	vector<int> res(arr.size());

	stck.push(0); // [0, ]


	for(int i=1;i<arr.size();i++)
	{
		while(!stck.empty()&& arr[i] <  arr[stck.top()])
		{
			res[stck.top()] = arr[i];
			stck.pop();
		}
		stck.push(i);
	}

	while(!stck.empty())
	{
		res[stck.top()] = -1;
		stck.pop();
	}

	return res;

}


vector<int> pse(vector<int>& arr)
{

	reverse(arr.begin(),arr.end());

	vector<int> ans = nse(arr);
	return ans;
}



int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
	vector<int> test_case = {30 ,12, 40, 20, 2, 4, 10};

	vector<int> ans = pse(test_case);

	for(auto ele:ans)
	{
		cout<<ele<<" ";
	}
 
	return 0;

}