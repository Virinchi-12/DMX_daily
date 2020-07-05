/*560. Subarray Sum Equals K
Medium

4630

149

Add to List

Share
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2
 

Constraints:

The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n=nums.size(),i,res=0,summ=0;
        unordered_map<int,int> m;
        m[0]=1;
        for(i=0;i<n;i++){
            summ=summ+nums[i];
            
            // Find out all subarrays ending at j with sum k
            // Add to the result
            if(m.find(summ-k)!=m.end())
            res=res+m[summ-k];
            
            m[summ]++;
            
        }
        return res;
    }
};
