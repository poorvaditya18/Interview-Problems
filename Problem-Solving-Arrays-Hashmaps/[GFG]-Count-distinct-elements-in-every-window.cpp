#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        vector<int> ans;
        unordered_map<int,int> mpp;
        int i=0;
        int j=0;
        int count = 0;
        while(j<n)
        {
            
            mpp[A[j]]++;
            
            // window size 
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                
                ans.push_back(mpp.size());
                
                mpp[A[i]]--; // decrease the key count 
                if(mpp[A[i]]==0) 
                {
                    // count becomes zero then remove the key 
                    mpp.erase(A[i]);
                }
                i++;
                j++;
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