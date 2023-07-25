#include<bits/stdc++.h>
using namespace std;


// painter partition problem 
// mimiax problem
// painter can only paint continous board

// mid represents -> the maximum sum of any subarray 
// we will check whether mid is good or not 
// determine if it is possible to divide the array into subarray such that
// no subarray has the sum greater than the mid value .
#include<bits/stdc++.h>
using namespace std;

bool goodFunc(vector<int>&boards,int mid, int k)
{
    int numberOfPainters = 1;
    int currSum = 0;
    for(int i=0;i<boards.size();i++)
    {
        currSum+=boards[i];
        if(currSum>mid)
        {
            numberOfPainters++;
            currSum = boards[i];
        }
    }
    if(numberOfPainters>k)
    {
        return false;
    }
    return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    // Intuition -> Binary Search on MiniMax
    int n = boards.size();
    int sum = 0;
    int ans = -1;
    int low = *max_element(begin(boards),end(boards));
    for(int i=0;i<boards.size();i++)
    {
        sum+=boards[i];
    }
    int high = sum;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        // mid represents the maximum subarray sum 
        // check mid
        if(goodFunc(boards,mid,k))
        {
            ans = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return ans;
}



int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	



	
 
	return 0;

}