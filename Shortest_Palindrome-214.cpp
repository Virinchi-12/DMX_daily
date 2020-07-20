/*
214. Shortest Palindrome
Hard

1157

123

Add to List

Share
Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

Example 1:

Input: "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: "abcd"
Output: "dcbabcd"
*/

//The idea is to calculate the maximum length of prefix palindrome present in the input string.
// Say the input string has a 'k' length prefix palindrome then the answer is reverse of the remaining n-k elements and attching this to the original string
// res= rev(n-k elements) + s
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
    string shortestPalindrome(string s) {
       string r=s;
        reverse(r.begin(),r.end());
        string k=s+"#"+r;
        vector<int> v=buildLPS(k);
        int n=v.size();
        int p=v[n-1];
        string res;
        for(int i=s.size()-1;i>=p;i--){
            res=res+s[i];
        }
        res+=s;
        return res;
    }
};
