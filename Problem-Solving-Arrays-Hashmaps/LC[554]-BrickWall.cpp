#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int leastBricks(vector<vector<int>>& wall) 
    {

        // idea to get minimum crosses , we should get maximum number of gaps. 
        // because gaps + cross = sum
        int sz = wall.size();
        int maxGap = 0;

        unordered_map<int,int> gapsFrequency; // will store the gaps with its count 
        int gaps;
        for(auto &row:wall)
        {
            gaps = 0; // for every row 
            for(int i=0;i<row.size()-1;i++)
            {
                gaps+=row[i];
                gapsFrequency[gaps]++;
            }

        }

        // now find the key which have maximum gap
        for(auto &ele:gapsFrequency)
        {
            maxGap = max(maxGap,ele.second);
        }

        // minimum cross = row - maximum;
        return sz - maxGap;
        
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