/*402. Remove K Digits
Medium

Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<char> s;
        int count=0;
        int n=num.size();
        
        if(n==k) return "0";
        int a=k;
        for(int i=0;i<n ;i++){
            
            while(!s.empty() && int(s.top())>int(num[i]) && a!=0){
                s.pop();
                a--;
            }
            s.push(num[i]);
        }
        string res="";
        
        if(a!=0){
            while(a>0){
            s.pop();
                a--;
            }
                
        }

        stack<char> t;
        while(!s.empty()){
            t.push(s.top());
            s.pop();
        }
        
        while(t.top()=='0' && t.size()!=1)
            t.pop();
        
        while(!t.empty()){
            res=res+t.top();
            t.pop();
        }
        
        
        return res;
    }
};
