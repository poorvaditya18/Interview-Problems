#include<bits/stdc++.h>
using namespace std;

// Top Down Solution --> 
int maxProfit(vector<int> &val, vector<int> &wt, int n, int W)
{
	

	// To Avoid Recursive Calls 
	// KnapSack Top Down solution -> we will avoid recursive call

	// Here each cell represent a sub-problem in itself . 
	
	int t[n + 1][W + 1]; // DP matrix

	for (int i = 0; i <= n; i++)
	 {
		for (int j = 0; j <= W; j++) 
		{
			if (i == 0 || j == 0) // base case
				t[i][j] = 0;
			else if (wt[i - 1] <= j) 
			{ // current wt can fit in bag
				int val1 = val[i - 1] + t[i - 1][j - wt[i - 1]]; // take current wt
				int val2 = t[i - 1][j]; // skip current wt
				t[i][j] = max(val1, val2);
			}
			else if (wt[i - 1] > j) // current wt doesn't fit in bag
				t[i][j] = t[i - 1][j];
		}
	}

	return t[n][W]; // last cell of the matrix will represent maximum profit . 
}

int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
 
	return 0;

}