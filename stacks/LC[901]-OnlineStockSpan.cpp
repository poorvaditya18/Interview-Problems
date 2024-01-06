#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int,int>> stck; // this will store
    int i = 0; // for initial index
    StockSpanner() {}

    int next(int price) {
        if(stck.empty())
        {
            // then push element as well as its index.
            stck.push({price,i});
            i++; 
            return 1;
        }
        else
        {
            int span_duration;
           // now when stack is not empty 
           // find the pge index
           // price is currPrice 
           // stck.top().first is previous price of stock
           while(!stck.empty() && price >= stck.top().first)
           {
               stck.pop();
           }
           if(stck.empty())
           {
               // i.e there will no day where price of stock was lesser than current day's price.
               // ans = i - (-1);
               span_duration = i+1;
           }
           else
           {
               // index of current - pge's index
               span_duration = i - (stck.top().second);
           }
           stck.push({price,i});
           i++;
           return span_duration;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
 
	return 0;

}