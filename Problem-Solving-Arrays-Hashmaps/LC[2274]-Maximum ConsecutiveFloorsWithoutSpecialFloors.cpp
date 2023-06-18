#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) 
    {
        

        // THIS APPROACH WILL GIVE TLE , SPACE LIMIT EXCEED FOR LARGE CONSTRAINTS ->
        //  sort(special.begin(),special.end());
        // make hashmap to find the possible candidate which can be start of the sequence 
        // unordered_map<int,bool> mpp;
        // vector<int> allKeys;

        
        // int maxLength = 0;
        // int maxStartingNo = 0;
        // int j=0; //will traverse special array 


        // // generate elements 
        //     for(int i=bottom;i<=top;i++)
        //     {
        //         // perform some operation on the element
        //         if(j<special.size()&&special[j]==i)
        //         {
        //             j++;
        //         }
        //         else
        //         {
        //             if(mpp.find(i-1)==mpp.end())
        //             {
        //                 // not present 
        //                 // then i can be start of the sequence 
        //                 mpp[i]=true; // mark as true
        //             }
        //             else
        //             {
        //                 // i-1 is present 
        //                 // i cannot be start of the sequence 
        //                 // mark i as false 
        //                 mpp[i]=false;
        //             }
        //         }
        //     }

        //     for(auto ele:mpp)
        //     {
        //         // insert keys in allKeys vector
        //         allKeys.push_back(ele.first);
        //     }

        //     for(int i=0;i<allKeys.size();i++)
        //     {
        //         int pstart = allKeys[i];
        //         int count = 0;
        //         //check whether key is candidate key or not
        //         if(mpp[pstart]==true)
        //         {
        //             while(mpp.find(pstart+count)!= mpp.end())
        //             {
        //                 count+=1;
        //             }
        //         }

        //         maxLength = max(maxLength,count);
        //         maxStartingNo = pstart;
        //         count = 0;
        //     }
            
        // return maxLength;

        sort(special.begin(),special.end());

        int maxConsecutive = -1;
        maxConsecutive = max(maxConsecutive,special[0]-bottom);
        maxConsecutive = max(maxConsecutive,top-special[special.size()-1]);

        for(int i=1;i<special.size();i++)
        {
            maxConsecutive = max(maxConsecutive, special[i]-special[i-1]-1);
        }
        return maxConsecutive;
        
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