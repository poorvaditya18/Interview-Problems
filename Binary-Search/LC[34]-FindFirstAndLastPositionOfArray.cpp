#include<bits/stdc++.h>
using namespace std;



// find first index
int checkFirstPosition(vector<int>&nums,int k)
{

		int res = -1;
		int low = 0;
		int high = nums.size()-1;

		while(low<=high)
		{
			int mid = low +(high-low)/2;
			if(nums[mid]==k)
			{
				res = mid;
				high = mid-1;
			}
			else if(nums[mid]>k)
			{
				high = mid-1;
			}
			else
			{
				low = mid+1;
			}
		}
		return res;
}


// find last index
int checkLastPosition(vector<int>&nums,int k)
{
		int res = -1;
		int low = 0;
		int high = nums.size()-1;

		while(low<=high)
		{
			int mid = low +(high-low)/2;
			if(nums[mid]==k)
			{
				res = mid;
				low = mid +1;
			}
			else if(nums[mid]>k)
			{
				high = mid-1;
			}
			else
			{
				low = mid+1;
			}
		}
		return res;
}





int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	vector<int> nums = {5,7,7,8,8,10};
	int target = 8;
	cout<<checkFirstPosition(nums,target)<<endl;
	cout<<checkLastPosition(nums,target)<<endl;
 
	return 0;

}