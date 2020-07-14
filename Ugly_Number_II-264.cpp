/*
264. Ugly Number II
Medium

1905

121

Add to List

Share
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  

1 is typically treated as an ugly number.
n does not exceed 1690.
*/

class Solution {
public:
    typedef long long int ll;
    int nthUglyNumber(int n) {
        
        //using min heap
        
        if(n==1) return 1;
        priority_queue<ll,vector<ll>, greater<ll> > pq;
        
        pq.push(2);
        pq.push(3);
        pq.push(5);
        while(n>2){
            ll t=pq.top();
            pq.pop();
             if(t%5==0){
                 pq.push(t*5);
                 
             }
            else if(t%3==0){
                pq.push(t*3);
                pq.push(t*5);
            }
            else if(t%2==0){
                pq.push(t*2);
                 pq.push(t*3);
                pq.push(t*5);
            }
            n--;
        }
        return pq.top();
        
        //simple vector solution
        vector<int> res;
        res.push_back(1);
        int i=0,j=0,k=0;
        
        int count=0;
        while(res.size()<n){
            res.push_back(min(res[i]*2,min(res[j]*3,res[k]*5)));
            if(res.back()==res[i]*2)
                i++;
            if(res.back()==res[j]*3)
                j++;
            if(res.back()==res[k]*5)
                k++;
        }
        return res.back();
    }
};
