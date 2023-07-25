#include<bits/stdc++.h>
using namespace std;


bool goodFunc(vector<int>&stalls,int mid,int c)
{
    int CurrentNoOfCows = 1;
    int LastPosition = stalls[0]; // placing first cow at first position
    for(int i=1;i<stalls.size();i++)
    {
        if(stalls[i]-LastPosition>=mid)
        {
            // place another cow
            CurrentNoOfCows++;
            //update last positon
            LastPosition=stalls[i];
        }
        if(CurrentNoOfCows==c) return true;
    }
    return false; 
}

int aggressiveCows(vector<int> &stalls, int c)
{
    //    Write your code here.
    // sort the stalls 
    int n = stalls.size(); // number of stalls;
    sort(stalls.begin(),stalls.end());
    int low = 1;
    int maxi = -1;
    int ans = -1;
    for(int i=0;i<n;i++)
    {
        maxi = max(maxi,stalls[i]);
    }
    int high = maxi;
    while(low<=high)
    {
        // mid represents minimum distance between two cows
        int mid = low + (high-low)/2;
        if(goodFunc(stalls,mid,c))
        {
            // then try to maximise the vlaue 
            ans = mid;
            low = mid +1 ;
        }
        else
        {
            high = mid-1;
        }
    }
    return ans;
}



int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
 
	return 0;

}