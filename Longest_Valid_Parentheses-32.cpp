/*
32. Longest Valid Parentheses
Hard

3513

136

Add to List

Share
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/

//Explanation in book

class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(), i;
        if(n==0) return 0;
        vector<int> dp(n,0);
        int res=0;
        dp[0]=0;
        for(i=1;i<n;i++){
            if(s[i]=='(')
                dp[i]=0;
            else{
                //Find the match
              int  matchIdx=i-dp[i-1]-1;
                if(matchIdx >= 0 && s[matchIdx]==')')
                    dp[i]=0;
                else if(matchIdx>=0){
                    
                    dp[i]=2+dp[i-1];
                    
                    //Extend the chain
                    if(matchIdx-1 >= 0)
                        dp[i]+=dp[matchIdx-1];
                }
                    
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};
