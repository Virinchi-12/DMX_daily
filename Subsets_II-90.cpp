/*90. Subsets II
Medium

Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
    
     void f(vector<int> &nums, int startIdx, vector<int> currSet, vector<vector<int>> &res){
        
        // Base step
        // Solution to the smallest subproblem
        int n = nums.size();
        if(startIdx == n){
            res.push_back(currSet);
            return;
        }
        
        //Decision: Include it 0 or more times
    
         //Let's find out the first index which contains a different element
         int i,j;
         i=startIdx+1;
         while(i<n && nums[i]==nums[i-1])
             i++;
         
         j=i;
         
        // Include 0 times
        f(nums, j, currSet, res);
        
        // Include 1 or more times
         for(i=startIdx;i<j;i++){
             currSet.push_back(nums[startIdx]);
             f(nums, j, currSet, res);
         }
        
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<vector<int>> res;
        vector<int> currSet;
        sort(nums.begin(),nums.end());
        f(nums, 0, currSet, res);
        
        return res;
    }
};

