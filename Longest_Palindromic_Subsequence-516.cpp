/*
516. Longest Palindromic Subsequence
Medium

2041

180

Add to List

Share
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
 

Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.
*/

//Use LCS here 
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        
        vector<vector<int> > dp(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<=m;i++){
            
            for(int j=1;j<=n;j++){
                
                 if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
    
    int longestPalindromeSubseq(string s) {
        string k=s;
            reverse(s.begin(),s.end());
        return longestCommonSubsequence(s,k);
    }
};
