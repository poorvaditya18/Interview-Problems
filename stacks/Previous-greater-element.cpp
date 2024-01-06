#include<bits/stdc++.h>
using namespace std;


// previous greater element 
// Input : arr[] = {10, 4, 2, 20, 40, 12, 30}
// Output :         -1, 10, 4, -1, -1, 40, 40


//  {30,12,40,20,2,4,10}
//   40,40,-1,-1,4,10,-1
vector<int> nge(vector<int>& arr)
{

	int n = arr.size();
	vector<int> res(n);

	stack<int> stck; // push indexes

	stck.push(0); // [0,]

	for(int i=1;i<arr.size();i++)
	{

		while(!stck.empty() && arr[i] > arr[stck.top()] )
		{

			// make index of that element --> current element 
			res[stck.top()]= arr[i];
			// pop out 
			stck.pop();
		}
		stck.push(i); // push current element's index
	}

	// finally for remaining element make index as -1 as there is no next greater element
	while(!stck.empty())
	{
		res[stck.top()] = -1;
		stck.pop();
	}

	return res;

}

vector<int> pge(vector<int> & arr)
{

	// reverse the array 
	reverse(arr.begin(),arr.end());

	// find the nge
	vector<int> ans = nge(arr);

	return ans;

}



int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	

	vector<int> test_case = {10, 4, 2, 20, 40, 12, 30};


	vector<int> ans = pge(test_case);
	cout<<endl;
	for(auto ele:ans)
	{
		cout<<ele<< " ";
	}
 
	return 0;

}