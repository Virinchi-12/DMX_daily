/*
3. Longest Substring Without Repeating Characters
Medium

9567

575

Add to List

Share
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;
        int n=s.size();
        vector<int> m(256,-1); ///a map which stores the last occurence(index) of each character
        int p1=0,p2; //two pointers 
        for(p2=0; p2<n; p2++){
            //update left pointer
            if(m[s[p2]]==-1 || m[s[p2]]<p1) // Or just if(m[s[p2]] < p1) would work because it takes care of all cases
            maxlen=max(maxlen,p2-p1+1); // increase the running length while there are no repeating characters  
            else
            p1=max(p1,m[s[p2]]+1); //On encountering repetitive chars i.e s[p1]=s[p2], increment p1 to last pos where s[p2] is found +1
                                
            m[s[p2]]=p2; //update index 
        }
        return maxlen;
    }
};
