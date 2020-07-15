/*
226. Invert Binary Tree
Easy

3383

55

Add to List

Share
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
         if(root==NULL) return root;
        TreeNode* lefttt=invertTree(root->left);
        TreeNode* righttt=invertTree(root->right);
        root->right=lefttt;
        root->left=righttt;
        return root;
    }
};
