#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> stck;
    vector<int> res(n);

    stck.push(0);

    for(int i=0;i<n;i++)
    {
        while(!stck.empty()&& arr[i] < arr[stck.top()])
        {
            res[stck.top()] = arr[i];
            stck.pop();
        }
        stck.push(i);
    }

    while(!stck.empty())
    {
        int topIdx = stck.top();
        res[topIdx] = -1;
        stck.pop();
    }
    return res;
}

int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
 
	return 0;

}