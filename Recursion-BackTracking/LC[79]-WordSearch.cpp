#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        int m = board.size();
        int n = board[0].size();
        for(int row=0;row<m;row++)
        {
            for(int col = 0;col<n;col++)
            {

            	// check from the first idx
                if(Helper(row,col,word,0,m,n,board))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool Helper(int row,int col , string &word , int idx,int m,int n,vector<vector<char>>&board)
    {
    	// if anytime idx becomes greater than word length , then you have got the word
        if(idx>=word.length())
        {
            return true;
        }

        // matrix edge cases and also check the current board element 
        if(row<0 || row==m || col<0 || col==n || board[row][col]!=word[idx] )
        {
            return false;
        }

        // if got the matching character then mark that with some other character
        board[row][col]='#'; 

        // go to all the possible directions 
        if(Helper(row-1,col,word,idx+1,m,n,board)) return true;
        if(Helper(row,col+1,word,idx+1,m,n,board)) return true;
        if(Helper(row+1,col,word,idx+1,m,n,board)) return  true;
        if(Helper(row,col-1,word,idx+1,m,n,board)) return  true;

        //if not found any matching character then mark the current cell with original character and backtrack 
        board[row][col]=word[idx];
        return false;
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