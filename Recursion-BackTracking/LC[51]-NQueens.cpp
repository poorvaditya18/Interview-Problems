#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        // n queens -> n x n matrix
        string str;
        str.append(n,'.');
        vector<string> board(n,str);
        vector<vector<string>> ans;
       NQueensHelper(board,0,n,ans);  
       return ans;
    }
    
    void NQueensHelper(vector<string> &board,int queensPlaceSoFar,int totalQueens,vector<vector<string>> &ans)
    {
            // we can say totalQueens will represent row 
            if(totalQueens == queensPlaceSoFar)
            {
                // push theh solution the vector
                ans.push_back(board);
                return ;
            }

            for(int j=0;j<totalQueens;j++)
            {
                if(canPlace(board,totalQueens,queensPlaceSoFar,j))
                {
                     // mark board with Q
                     board[queensPlaceSoFar][j]='Q';

                     // search for the possible valid arrange for the next queen on next row 
                     NQueensHelper(board,queensPlaceSoFar+1,totalQueens,ans);

                     board[queensPlaceSoFar][j]='.';
                }
            }
    }

    bool canPlace(vector<string> &board,int n,int currRow,int currCol)
    {
        // we will not check row because we will place every queen at consecutive rows.

        // check column 
        for(int r=0;r<currRow;r++)
        {
            if(board[r][currCol]=='Q')
            {
                return false;
            }
        }

        int row, col;
        // check right diagonal 
         row= currRow;
         col = currCol;
        while(row>=0 and col<n)
        {
            if(board[row][col]=='Q')
            {
                return false;
            }
            row--;
            col++;
        }

        // left diagonal 
         row = currRow;
         col = currCol;
         while(row>=0 and col>=0)
         {
             if(board[row][col]=='Q')
             {
                 return false;
             }
             row--;
             col--;
         }

       return true;

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