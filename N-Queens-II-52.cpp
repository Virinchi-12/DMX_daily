/*52. N-Queens II
Hard

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other


Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example:

Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/
class Solution {
public:
    
    void helper(int k,vector<bool>&col,vector<bool>& d1,vector<bool>&d2,int n,int &count){
        //Base case
        if(k==n){
            count++;
            return;
        }
        //Recurrence
        //Placing a queen in each row while checking for its previous column,d1 and d2 arrays
        for(int i=0;i<n;i++){
            if(col[i]==false && d1[k-i+n-1]==false && d2[k+i]==false){
                col[i]=true;
                d1[k-i+n-1]=true;
                d2[k+i]=true;
                helper(k+1,col,d1,d2,n,count);
                col[i]=false;
                d1[k-i+n-1]=false;
                d2[k+i]=false;
            }
        }
    }
    int totalNQueens(int n) {
        vector<bool>col(n,false);
        vector<bool>d1(2*n-1,false);
        vector<bool>d2(2*n-1,false);
        int count=0;
        helper(0,col,d1,d2,n,count);
        return count;
    }
};
