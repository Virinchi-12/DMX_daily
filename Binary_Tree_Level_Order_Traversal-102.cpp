/*
102. Binary Tree Level Order Traversal
Medium

3021

74

Add to List

Share
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root,int level,vector<vector<int>> &res){
      
         if(root==NULL)
              return;
        
        if(res.size()==level){
            res.push_back({});
        }
         
        
         res[level].push_back(root->val);  
        
        helper(root->left,level+1,res);
        helper(root->right,level+1,res);
        
       
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> res;
        helper(root,0,res);
        return res;
    }
};
