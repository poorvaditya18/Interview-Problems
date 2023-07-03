#include<bits/stdc++.h>
using namespace std;

int res=0;
void f(int x , int n,int i)
{
    int p = (int)pow(i,n); //  calculate : p = i^n
     //base case 
     if(x==0)
     {
         // found the valid power sum 
         res++;
         return ;
     }
     if(i*i>x)
     {
        // because it cannot be out of range [1 , sqrt(x)]
         return;
     }
     if(x<0)
     {
         return;
     }
    
    // recurrence relation -->
    f(x-p,n,i+1); // choose element 
    f(x,n,i+1); // dont choose element      
}

int powerSum(int X, int N) {
    
    // X , N --> X belongs in this range [1,sqrt(X)]
    f(X, N, 1);
    return res;      
}


int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
 
	return 0;

}