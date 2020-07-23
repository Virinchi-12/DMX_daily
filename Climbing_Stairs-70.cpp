/*
70. Climbing Stairs
Easy

4410

142

Add to List

Share
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
*/

class Solution {
public:
    //prototype (top-down)
    //return explicitly
    int helper(int n,vector<int> &dp){
        //Base case
        if(n==0 || n==1) return 1;
        //Checking if the problem has already been solved
        //Look-up the dp table
        //Initial value of the dp table comes in handy
        if(dp[n]!=-1) return dp[n];
        
        //Recursive step
        int k= helper(n-1,dp)+helper(n-2,dp);
        
        //Store the solution
        dp[n]=k;
        return k;
    }
    int climbStairs(int n) {
//         //Bottom up
//         //Structure of the table
//         vector<int> dp(n+1,-1);
        
//         //Order of filling the table
//         //Bottom up
//         //Smallest to largest
//         dp[1]=1;
//         dp[0]=1;
//         for(int i=2;i<=n;i++){
//             dp[i]=dp[i-1]+dp[i-2];
//         }
//         return dp[n];
        
        //Top down
        //Structure of the table
        vector<int> dp(n+1,-1);
        
        //Solve the sub problems as you encounter them
        //Tool? <--Recursion
        return helper(n,dp);
    }
};
