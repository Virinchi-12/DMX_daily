/*51. N-Queens
Hard

1812

73

Add to List

Share
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*/
class Solution {
public:
    
        void helper(int k,vector<bool>&col,vector<bool>& d1,vector<bool>&d2,vector<string> &curset,vector<vector<string>> &res){
        //Base case
            int n=col.size();
        if(k==n){
            res.push_back(curset);
            return;
        }
        //Recurrence
        //start with placing kth queen in kth row
        //Placing a queen in each row while checking for its previous column,d1 and d2 arrays
            //Iterate through the colums
        for(int i=0;i<n;i++){
            if(col[i]==false && d1[k-i+n-1]==false && d2[k+i]==false){
                col[i]=true;
                d1[k-i+n-1]=true;
                d2[k+i]=true;
                curset[k][i]='Q';
                helper(k+1,col,d1,d2,curset,res);
                col[i]=false;
                d1[k-i+n-1]=false;
                d2[k+i]=false;
                 curset[k][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
         vector<bool>col(n,false);
        vector<bool>d1(2*n-1,false);
        vector<bool>d2(2*n-1,false);
        vector<string> curset(n,string(n,'.'));
        vector<vector<string>> res;
        helper(0,col,d1,d2,curset,res);
        return res;
    }
};
