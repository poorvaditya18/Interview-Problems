#include<bits/stdc++.h>
using namespace std;


int func(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > m) return 2;
    }
    if (ans == m) return 1;
    return 0;
}

int NthRoot(int n, int m) {
  // Write your code here.

  // search space 0 - m 
  int low = 1;
  int high = m;
  
  while(low<=high)
  {
    int mid = low+(high-low)/2;
    int temp =n;
    long long  res=1;
     // mid ele --> mid * mid* mid .. n times
     // calculate 
     int midN = func(mid,n,m);
     if(midN==1)
     {
       return mid;
     }
     else if(midN==2)
     {
       high = mid-1;
     }
     else
     {
       low = mid+1;
     }
  }
  return -1;
}



int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
 
	return 0;

}