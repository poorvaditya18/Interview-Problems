#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int largestRectangleArea(vector<int> heights) 
    {
        stack<int> stk;
        stk.push(-1);
        int max_area = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (stk.top() != -1 and heights[stk.top()] >= heights[i]) {
                int current_height = heights[stk.top()];
                stk.pop();
                int current_width = i - stk.top() - 1;
                max_area = max(max_area, current_height * current_width);
            }
            stk.push(i);
        }
        while (stk.top() != -1) {
            int current_height = heights[stk.top()];
            stk.pop();
            int current_width = heights.size() - stk.top() - 1;
            max_area = max(max_area, current_height * current_width);
        }
        return max_area;

    }

    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        // Question is the extended version of largestRectangle in histogram

        int row= matrix.size();
        int col = matrix[0].size();

        vector<int> nums(col);

        // for first row 
        for(int j=0;j<col;j++)
        {
            nums[j] = matrix[0][j] - '0';
        }

        // calculate area for first row 
        int area = largestRectangleArea(nums);

        // calculate for remaining 
        for(int i = 1 ; i < row ; i++)
        {
            for(int j = 0; j < col ; j++)
            {
                if(matrix[i][j]=='0')
                {
                    nums[j]=0;
                }
                else
                {
                    nums[j] = nums[j] + (matrix[i][j] - '0');
                }
            }

            // calculate area 
            area = max(area , largestRectangleArea(nums));
        }

        return area;
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