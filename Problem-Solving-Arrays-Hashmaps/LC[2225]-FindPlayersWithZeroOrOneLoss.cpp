#include<bits/stdc++.h>
using namespace std;


 vector<vector<int>> findWinners(vector<vector<int>>& matches) 
 {
        
        map<int,vector<int>> mpp; // will store player , lose from which player 
        vector<int> one_loss,zero_loss;
        vector<vector<int>> ans;

        for(int i=0;i<matches.size();i++)
        {
            int winner = matches[i][0];
            int loser = matches[i][1];

            


            if(mpp.find(loser)!=mpp.end())
            {
            	if(mpp.find(winner)==mpp.end())
            	{
            		mpp.insert(pair<int,vector<int>>(winner,{}));
            	}
                // if present 
                mpp[loser].push_back(winner);
            }
            else
            {
                // if not present insert both winner and losser 
                mpp.insert(pair<int,vector<int>>(loser,{winner}));
                mpp.insert(pair<int,vector<int>>(winner,{}));
            }
        }
        for(auto ele:mpp)
        {
            int key = ele.first;
            vector<int> value = ele.second;
            if(value.size()==0)
            {

            	// cout<<"Players with 0 loss : "<<key<<endl;
                // player with 0 loss
                zero_loss.push_back(key);

            }
            if(value.size()==1)
            {
            	// cout<<"Player with 1 loss: "<<key<<endl;
                one_loss.push_back(key);
            }
            // cout<<"Key: "<<key<<" Value -->";
            // for(auto ele:value)
            // {
            // 	cout<<ele<<" ";
            // }
            // // cout<<endl;
        }
        sort(zero_loss.begin(),zero_loss.end());
        sort(one_loss.begin(),one_loss.end());
        ans.push_back(zero_loss);
        ans.push_back(one_loss);
        return ans;
    }

int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
	vector<vector<int>> matches = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};

	vector<vector<int>> ans = findWinners(matches);
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<" ";
		}	
		cout<<endl;
	}
 
	return 0;

}