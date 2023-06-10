#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles)
    {
            // using map to store rectangle's reduced ratio and count 
            int n = rectangles.size();
            long long count = 0;    

            unordered_map<double,int> mpp;

            for(int i=0;i<n;i++)
            {
                double widthHeightRatio = rectangles[i][0]/(double)rectangles[i][1];
                mpp[widthHeightRatio]++;
            }

            // since for pair will be formed when you choose 2 rectangles 
            // hence we will use nC2 for those who will have same ratio. 
            for(auto i:mpp)
            {
                long long x = i.second;
                x = (x*(x-1)/2.0);
                count+=x;
            }
            return count ;
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