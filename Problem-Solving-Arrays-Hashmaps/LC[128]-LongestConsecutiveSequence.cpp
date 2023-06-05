#include<bits/stdc++.h>
using namespace std;


    int longestConsecutive(vector<int>& nums) 
    {
        // hashmap 
               unordered_map<int,bool> mpp;
        vector<int> keys;
        int maxLength = 0;
        int maxStartingNo = 0;

        for(auto val:nums)
        {
        	mpp[val] = true;
            // for every val  , check for val-1 , val +1  whether present or not , if present then mark the value as false. as it cannot be start of the sequence.
            if(mpp.find(val-1)!= mpp.end())
            {
                // means present 
                mpp[val] = false;
            }
            if(mpp.find(val+1)!= mpp.end())
            {
                mpp[val+1] = false;
            }
            
        }


        // insert all the keys in the hashmap 
        for(auto ele:mpp)
        {
        	   cout<<ele.first<<" "<<ele.second<<endl;
                keys.push_back(ele.first);
        }

        // now iterate over keys and check 
        for(int i=0;i<keys.size();i++)
        {
            int pstart = keys[i];
           int count = 0;
            
            if(mpp[pstart]==true)
            {
               // start check for pstart + count 
               while(mpp.find(pstart+count)!= mpp.end())
               {
                   count+=1;
               }
            }

           maxLength = max(maxLength,count);
           maxStartingNo = pstart;
           count = 0;
        }
        return maxLength;

    }



int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
	vector<int> arr = {100,4,200,1,3,2};
	cout<<longestConsecutive(arr)<<endl;
 	
	return 0;

}