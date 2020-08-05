/*
200. Number of Islands
Medium

5868

202

Add to List

Share
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/
class Solution {
public:
    void dfs(vector<vector<char>>&grid, int i,int j,vector<vector<bool>>&visited){
           
            int m=grid.size(),n=grid[0].size();
                visited[i][j]=true;
                if(i+1<m && grid[i+1][j]=='1' && !visited[i+1][j]) dfs(grid, i+1,j,visited);
                if(i-1>=0 && grid[i-1][j]=='1' && !visited[i-1][j]) dfs(grid, i-1,j,visited);

                if(j+1<n && grid[i][j+1]=='1' && !visited[i][j+1]) dfs(grid, i,j+1,visited);

                if(j-1>=0 && grid[i][j-1]=='1' && !visited[i][j-1]) dfs(grid, i,j-1,visited);

    }
    
    int numIslands(vector<vector<char>>& grid) {
         if(grid.size()==0) return 0;
        int m=grid.size(),n=grid[0].size(),res=0;
        vector<vector<bool> > visited(m, vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(grid,i,j,visited);
                    res++;
                }
                    
            }
        }
        return res;
    }
};
