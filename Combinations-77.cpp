/*Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
class Solution {
public:
    void func(vector<int> &nums,int startIndx,int k,vector<int> currSet,vector<vector<int>> &res){
        
        int n=nums.size();
        if(k==0){
            res.push_back(currSet);
            return ;
        }
        
         // k > 0 && vector was empty
        if(startIndx == nums.size())
            return;
        //Pruning
        if(k>n-startIndx)
            return;
        
        //exclude
        func(nums,startIndx+1,k,currSet,res);
        
        //include
        currSet.push_back(nums[startIndx]);
        func(nums,startIndx+1,k-1,currSet,res);
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        vector<int> currSet;
        vector<vector<int>> res;
        func(nums,0,k,currSet,res);
        return res;
    }
};
