/*
974. Subarray Sums Divisible by K
Medium

842

68

Add to List

Share
Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.

 

Example 1:

Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
 

Note:

1 <= A.length <= 30000
-10000 <= A[i] <= 10000
2 <= K <= 10000
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n=nums.size(),i,res=0,summ=0,r3;
        unordered_map<int,int> m;
        m[0]=1;
        for(i=0;i<n;i++){
            summ=summ+nums[i];
            
            r3=summ%k;
          //  if(m.find(summ-k)!=m.end()){
            res=res+m[r3];
             // res=res+m[k+r3];
             // res=res+m[r3-k];
        //}
            
            m[r3]++;
            
        }
        return res;
    }
};
