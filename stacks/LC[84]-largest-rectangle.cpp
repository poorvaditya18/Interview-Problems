#include<bits/stdc++.h>
using namespace std;

    // for right smaller 
    vector<int> nse(vector<int> arr)
    {   

        // Write your code here.
        int n = arr.size();
        stack<int> stck;

        vector<int> res(n,-1);

        stck.push(0);

        for(int i=1;i<n;i++)
        {
            while(!stck.empty()&& arr[i] < arr[stck.top()])
            {
                // res[stck.top()] = arr[i];
                res[stck.top()] = i;
                stck.pop();
            }
            stck.push(i);
        }

        while(!stck.empty())
        {
            int topIdx = stck.top();
            res[topIdx] = res.size();
            stck.pop();
        }
        return res;

    }
    // for left smaller 
    vector<int> pse(vector<int> prev_arr)
    {
        // reverse 
        reverse(prev_arr.begin(),prev_arr.end());

        // nse 
        vector<int> res = nse(prev_arr);

        // for(auto ele : res)
        // {
        // 	cout<<ele<<" ";
        // }

        // cout<<endl;

        reverse(res.begin(),res.end());

        // for(auto ele : res)
        // {
        // 	cout<<ele<<" ";
        // }
        // cout<<endl; 

        for(int i=0;i<res.size();i++)
        {
        	if(res[i]!=-1)
        	{
        		res[i] = res.size()-1-res[i];
        	}
        }

        return res;
    }

    int largestRectangleArea(vector<int>& heights) 
    {


        int maxi = -1;

        vector<int> left_smaller = pse(heights); 

        vector<int> right_smaller = nse(heights);

        vector<int> rect_area(heights.size());

        for(int curr_ele = 0; curr_ele<heights.size();curr_ele++)
        {
            rect_area[curr_ele] = heights[curr_ele] * (right_smaller[curr_ele] - left_smaller[curr_ele] - 1 );
        }

        for(int i=0;i<rect_area.size();i++)
        {
            maxi = max(maxi,rect_area[i]);
        }
        return maxi;
    }


    int largestRectangleArea_using_nse_one_pass(vector<int> & heights)
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

int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
	vector<int> heights = {2,4};
	cout<<largestRectangleArea_using_nse_one_pass(heights)<<endl;

 	
	return 0;

}