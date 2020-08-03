/*
64. Minimum Path Sum
Medium

3166

63

Add to List

Share
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m=grid.size(), n=grid[0].size(), i, j;
        vector<vector<int> > dp(m,vector<int>(n,INT_MAX));
        
        //fill top most row with running sum
        dp[0][0]=grid[0][0];
        for(i=1;i<n;i++)
            dp[0][i]=dp[0][i-1]+grid[0][i];
        //fill left most column with running sum
        for(i=1;i<m;i++)
            dp[i][0]=dp[i-1][0]+grid[i][0];
        
        for(i=1;i<m;i++){
            for(j=1;j<n;j++){
                
                dp[i][j]=min(dp[i][j-1],dp[i-1][j]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};
