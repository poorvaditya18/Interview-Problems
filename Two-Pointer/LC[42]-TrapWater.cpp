#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) 
    {
        // Intuition : Water can be only accumulated in the building only if the height between the buildings are different 
        // and then min(left,right)-curr

        int n= height.size();
        int res=0;
        vector<int> leftMax(n); // store the left maximum height
        vector<int> rightMax(n); // store the right maximum height
        vector<int> ans(n);
        leftMax[0]=height[0];

        // left Max
        for(int i=1;i<n;i++)
        {
            leftMax[i]=max(leftMax[i-1],height[i]);
        }

        rightMax[n-1] = height[n-1];

        //right Max
        for(int i=n-2;i>=0;i--)
        {
            rightMax[i]=max(rightMax[i+1],height[i]);
        }

        // calculate 
        for(int i=0;i<n;i++)
        {
            ans[i]=min(leftMax[i],rightMax[i])-height[i];
        }
        for(auto i:ans)
        {
            res+=i;
        }
        return res;
    }
};
int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
 
	return 0;

}