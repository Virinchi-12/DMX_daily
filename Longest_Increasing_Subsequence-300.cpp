/*
300. Longest Increasing Subsequence
Medium

4873

109

Add to List

Share
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size(), i, j;
        if(n==0) return 0;
        int res=1;
        vector<int> dp(n,0);
        
        dp[0]=1;
        for(i=1;i<n;i++){
            dp[i]=1;
            
            for(j=i-1;j>=0;j--){
                
                if(nums[j]<nums[i])
                    dp[i]=max(dp[i],1+dp[j]);
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};
