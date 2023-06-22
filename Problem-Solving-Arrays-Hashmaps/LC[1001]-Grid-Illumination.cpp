#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    private:
        vector<vector<int>> adjacent = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}, {0,0}};
    public:
        vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) 
        {
            
            // map_1<int,int> --> will store rows, count of lamps in that particular row ;
            unordered_map<long long ,int> map_1;
            // map_2<int,int> --> will store cols, count of lamps in that particular column;
            unordered_map<long long ,int> map_2;
            // map_3<int,int> --> will store diagonal, count of lamps of the diagonal with x-y slope;
            unordered_map<long long ,int> map_3;
            // map_4<int,int> --> will store diagonal , count of lamps of the diagonal with x+y slope;
            unordered_map<long long,int> map_4;
            // map_5<int,bool> --> will check whether the particular lamp is off/on. giving 2-d array indexing as n*x+y
            unordered_map<long long,int> map_5;
            
            
            // precomputation 
            for(auto ele:lamps)
            {
                // ele[0]--> row
                // ele[1]--> column
                long long  x = ele[0];
                long long  y = ele[1];
                map_1[x]++;
                map_2[y]++;
                map_3[x-y]++;
                map_4[x+y]++;
                map_5[n*x+y]++;
            }

            vector<int> ans(queries.size());

            // answering the queries -> 
            for(int i=0;i<queries.size();i++)
            {
                long long  x = queries[i][0];
                long long y = queries[i][1];

                ans[i] = (map_1[x]>0 || map_2[y]>0 || map_3[x-y]>0 || map_4[x+y]>0) ? 1:0;
                
                // switch off all the 8 adjacent lamps
                for(auto adjLamps:adjacent)
                {
                    long long  x1 = x + adjLamps[0];
                    long long  y1 = y + adjLamps[1];
                    // now check , also keep edge condition 
                    if(x1 >= 0 && y1 >= 0 && x1 < n && y1 < n && map_5.count(n * x1 + y1))
                    {
                        // present 
                        int times = map_5[n*x1+y1];
                        map_1[x1]-= times;
                        map_2[y1]-= times;
                        map_3[x1-y1]-=times;
                        map_4[x1+y1]-=times;
                        map_5.erase(n*x1+y1);
                    }
                }
            }

            return ans;
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