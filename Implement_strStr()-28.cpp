/*
28. Implement strStr()
Easy

1606

1917

Add to List

Share
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/

class Solution {
public:
    vector<int> buildLPS(string s){
        int m=s.size();
        vector<int> lps(m,0);
        int i=0;
        int j=1;
        lps[0]=0;
        while(j<m){
            if(s[i]==s[j]){
                lps[j]=i+1;
                 i++;
                j++;
            }
            else{
                if(i==0){
                    lps[j]=0;
                    j++;
                }
                else{
                     i=lps[i-1];
                }
            }
        }
        return lps;
    }
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        if(m==0) return 0;
        
        vector<int> lps=buildLPS(needle);
        int i=0; // for iterating main string
        int j=0; //for iterating needle string
        
      
        // string a="aaa";
       
        while(i<n){
            if(haystack[i]==needle[j]){
                i++;
                j++;
                if(j==m)
                    return (i-m);
            }
            else{
                if(j==0) i++;
                else
               j=lps[j-1];
            }
        }
        return -1;
        
    }
};
