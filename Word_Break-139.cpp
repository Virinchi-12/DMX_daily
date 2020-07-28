/*
139. Word Break
Medium

4428

233

Add to List

Share
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n=s.size(),i,j;
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
            string word;
        vector<bool> dp(n+1,false);
        
        if(dict.find(s.substr(n-1,1))==dict.end())
            dp[n-1]=false;
        else
            dp[n-1]=true;
                
        cout<<dp[n-1];
        for(i=n-2;i>=0;i--){
                word="";
            for(j=i;j<n;j++){
                word+=s[j];
                
                // if(dict.find(word)==dict.end())
                //     continue;
                
                //If word is present in the dictionary
                if(dict.find(word)!=dict.end())
                   {
                       if ( j+1==n || dp[j+1]==true) {
                        dp[i]=true;
                        break;
                }
            }
        }
        }
        return dp[0];
        
      
    }
};
