/*
166. Fraction to Recurring Decimal
Medium

845

1808

Add to List

Share
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 2, denominator = 3
Output: "0.(6)"
*/

class Solution {
public:
    void afterdecimalhelper(long long rem,long long int d,string &res){
        
        // Print the part after the decimal
        // Strategy: Keep printing till I get a repetition
        // Once I get a repition, I will come back and insert a (
        // and a )
        // Let's track the numerator
        unordered_map<long long int,long long int> m;
        long long int q;
        
        while(rem>0){
            rem=rem*10;
        
            //  while(rem*10 < d){
            //     res += "0";
            //     rem = rem*10;
            // }
         
            if(m.find(rem) != m.end())
                break;
        
            q = rem/d;
            
            m[rem] = res.size();
            
            res += to_string(q);
            
            rem = rem%d;
    }
        
              
        if(rem == 0) return;
        
        // Insert the bracket
        string prefix = res.substr(0, m[rem]);
        string suffix = res.substr(m[rem], res.size()-m[rem]);
        
        res = prefix + "(" + suffix + ")";
        
            
    }
    string fractionToDecimal(int numerator, int denominator) {
        string res="";
        long long int n=numerator, d=denominator;
        
        if((n>0 && d<0) || (n<0 && d>0))
            res=res+'-';
        n=abs(n);
        d=abs(d);
        res=res+to_string(n/d);
        
        int rem=n%d;
        if(rem==0)
            return res;
        
        res=res+'.';
        
        cout<<rem;
        afterdecimalhelper(rem,d,res);
        
        return res;
        
        
    }
};
