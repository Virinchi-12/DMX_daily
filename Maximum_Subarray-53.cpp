/*
53. Maximum Subarray
Easy

8112

384

Add to List

Share
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        
//         if(n==1) return nums[0];
//                // if(n=1 && nums[0]<0) return 0;

//         int summ=INT_MIN/2,best=INT_MIN/2;
//         for(int i=0;i<n;i++)
//         {
//             summ=max(nums[i],summ+nums[i]);
//             best=max(summ,best);
//         }
//         return best;
        
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int>dp(n,-1);
        dp[0]=nums[0];
        int maxx=dp[0];
           for(int i=1;i<n;i++){
            dp[i]=max(nums[i],dp[i-1]+nums[i]);
            maxx=max(dp[i],maxx);
        }
        return maxx;
    }
};
