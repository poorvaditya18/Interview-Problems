#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> res; // this will store the result 

        // sort the intervals based on the starting value 
        sort(intervals.begin(),intervals.end(),[](vector<int> interval1, vector<int> interval2)
         {
            return interval1[0] < interval2[0];
         });



        res.push_back(intervals[0]);

        // then you will have sorted intervals adjacent to each other 
        for(int i=1;i<intervals.size();i++)
        {
            // merge on the basis of condition 
            int endOfLast = res[res.size()-1][1];
            int startOfCurr = intervals[i][0];

            if(endOfLast>=startOfCurr)
            {
                //merge them 
                res[res.size()-1][1] = max(endOfLast,intervals[i][1]);
            }
            else
            {
                // push the curr
                res.push_back(intervals[i]);
            }
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