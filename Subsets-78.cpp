/*78. Subsets
Medium

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

//Short and simple
class Solution {
public:
    // f takes in a suffix subarray and returns the set of possible subsets
    void f(vector<int> &nums, int startIdx, vector<int> currSet, vector<vector<int>> &res){
        
        // Base step
        // Solution to the smallest subproblem
        int n = nums.size();
        if(startIdx == n){
            res.push_back(currSet);
            return;
        }
        
        
        // Recursive step
        // Use the recurrence relation
        // f(ar, 0) = f(ar, 1) U {ar[0] U f(ar, 1)}
        
        // No contribution
        f(nums, startIdx+1, currSet, res);
        
        // Contribute this element
        currSet.push_back(nums[startIdx]);
        f(nums, startIdx+1, currSet, res);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> currSet;
        
        f(nums, 0, currSet, res);
        
        return res;
    }
};

//Basic version
class Solution {
public:
    
    vector<vector<int>> func(vector<int> &nums,int startIndex){
        int n=nums.size();
        if(startIndex==n)
            return {{}};
        
        vector<vector<int>> sub=func(nums,startIndex+1);
            vector<vector<int>> res;
        //Exclude 
        res=sub;
        //Include
         
        vector<int> r;
            for(int i=0;i<sub.size();i++){
                r=sub[i];
                r.push_back(nums[startIndex]);
                res.push_back(r);
            }
        return res;
        
    }
    
    //////Optimised code//////
    
//       void func(vector<int> &nums,int startIndex,vector<vector<int>> &res){
//         int n=nums.size();
//         if(startIndex==n){ 
//             res.push_back({});
//           return ;
//       }
        
//         vector<vector<int>> sub;
//           func(nums,startIndex+1,sub);
          
//         //Exclude 
//         res=sub;
//         //Include
         
//         vector<int> r;
//             for(int i=0;i<sub.size();i++){
//                 r=sub[i];
//                 r.push_back(nums[startIndex]);
//                 res.push_back(r);
//             }
//         //return res;
        
//     }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        
         return func(nums,0);
        // vector<vector<int>> res;
        // func(nums,0,res);
        // return res;
        
    }
};

