/*
91. Decode Ways
Medium

2670

2837

Add to List

Share
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/

class Solution {
public:
    int numDecodings(string s) {
       
        // dp[0] means an empty string will have one way to decode, dp[1] means the way to decode a string of size. Then check one digit and two digit combination and save the results along the way. In the end, dp[n] will be the end result.
        int n=s.size();
         vector<int> dp(n+1,0);
        
            //Order of filling the table
            //Bottom up
            //Smallest to largest
       
        
        dp[0]=1;
        if(s[0]=='0') dp[1]=0;
        else
        dp[1]=1;
        if(n==0) return 0;
        for(int i=2;i<=n;i++){
           
            if(s[i-1]>='1' && s[i-1]<='9')
            dp[i]+=dp[i-1];
            
            
            int a=stoi(s.substr(i-2,2));
                if(a>=10 && a<=26){
                    
                    dp[i]=dp[i]+dp[i-2];
                }
                
        }
        return dp[n];
        
    }
};
