#include<bits/stdc++.h>
using namespace std;

 void nextPermutation(vector<int>& nums) 
    {
        //method 1 -> using next_permutation() : returns lexicographical next permutation

        //method 2 -> generate all the permutation and then linearly traversing and finding next greater permutation 


        // method3 -
        // 1. iterate from left find the breakpoint where a[i]<a[i+1] therefore index1 =i
        // 2. iterate again from left find element greater than index1 element i.e arr[index2]>arr[index1] 
        // 3. swap(arr[index1],arr[index2])
        // 4. Reverse reverse(index1+1,last)
        
        // int n = nums.size(), k, l;
    	// for (k = n - 2; k >= 0; k--) 
        // {
        //     if (nums[k] < nums[k + 1]) 
        //     {
        //         break;
        //     }
        // }
    	// if (k < 0) 
        // {
    	//     reverse(nums.begin(), nums.end());
    	// } 
        // else 
        // {
    	//     for (l = n - 1; l > k; l--) 
        //     {
        //         if (nums[l] > nums[k])
        //         {
        //             break;
        //         }
        //     } 
    	//     swap(nums[k], nums[l]);
    	//     reverse(nums.begin() + k + 1, nums.end());
        // }


        int n = nums.size();
        int i= n-2;

        while(i>=0 && nums[i+1]<=nums[i])
        {
            // move in the back direction -->
            i--;
        }
        if(i>=0)
        {
            int j = n-1;
            while(nums[j]<=nums[i])
            {
                j--;
            }
            swap(nums[i],nums[j]);
            reverse(nums.begin()+i+1,nums.end());
        }
        else
        {
            reverse(nums.begin(),nums.end());
        }
    }

int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
 
	return 0;

}