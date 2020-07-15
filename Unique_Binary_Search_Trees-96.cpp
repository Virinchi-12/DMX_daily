/*
96. Unique Binary Search Trees
Medium

3408

123

Add to List

Share
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

class Solution {
public:
    //No of trees possible with root[i] is n_root[i]=n_root[i-1]*n_root[n-i]
       // T[n]=Sum{ T[root-1] * T[n-root]}
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int root=2;root<=n;root++){
            //dp[root]=0;
            for(int node=1;node<=root;node++){
                dp[root]+=dp[node-1]*dp[root-node];
            }
        }
        return dp[n];
    }
};
