/*
152. Maximum Product Subarray
Medium

4243

157

Add to List

Share
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n=nums.size(),i;
        if(n==1) return nums[0];
        
        int prod=1,max=INT_MIN;
        
        for(i=0;i<n;i++){
            prod=prod*nums[i];
            if(prod>max)
                max=prod;
            if(prod==0)
                prod=1;
        }
        cout<<max;
        prod=1;
          for(i=n-1;i>=0;i--){
            prod=prod*nums[i];
            if(prod>max)
                max=prod;
            if(prod==0)
                prod=1;
        }
       return max;
    }
};
