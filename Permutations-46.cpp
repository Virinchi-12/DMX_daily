/*Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/
class Solution {
public:
    
    ///***Both solutions Work*****////
    
    
//     void permutehelper(vector<int> &nums,vector<bool> visited,vector<int> curset,vector<vector<int>>&res){
        
//         int n=nums.size();
//         //Base Case
//         if(curset.size()==n){
//             res.push_back(curset);
//             return;
//         }
        
//         for(int i=0;i<n;i++){
//             if(visited[i]==false){
                
//                 visited[i]=true;
//                 curset.push_back(nums[i]);
//                 permutehelper(nums,visited,curset,res);
                
//                   visited[i]=false;
//                 curset.pop_back();
//             }
          
//         }
//     }
    
    void permutehelper(vector<int>& nums,int startIdx,vector<vector<int>> &res){
        int n=nums.size();
        if(startIdx==n){
            res.push_back(nums);
            //return;
        }
        
        for(int i=startIdx;i<n;i++){
            swap(nums[startIdx],nums[i]);
            permutehelper(nums,startIdx+1,res);
            swap(nums[i],nums[startIdx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        // int n=nums.size();
        // vector<bool> visited(n,false);
        // vector<vector<int>>res;
        // vector<int> curset;
        // permutehelper(nums,visited,curset,res);
        // return res;
        
        vector<vector<int>> res;
        permutehelper(nums,0,res);
        return res;
        
    }
};
