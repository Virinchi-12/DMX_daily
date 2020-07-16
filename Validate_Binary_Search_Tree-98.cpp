/*
98. Validate Binary Search Tree
Medium

3920

537

Add to List

Share
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/

*****Both solutions work********

class Solution {
public:
    
//     void noofnodes(TreeNode* node,int &count){
//         if(node==NULL)  return;
//         noofnodes(node->left,count);
//         count++;
//         noofnodes(node->right,count);
//     }
//     void inorder(TreeNode* node,vector<int>&r){
//         if(node==NULL)
//             return ;
//         inorder(node->left,r);
//         if(r.size()>0 && r[r.size()-1]>=node->val){
           
//         }
//          else
//               r.push_back(node->val);
//         inorder(node->right,r);
//     }
    bool check(TreeNode* &prev,TreeNode* cur){
        if(cur==NULL) return true;
        
        if(!check(prev,cur->left)) return false;
        if(prev!=NULL && prev->val>=cur->val) return false;
        prev=cur;
        return check(prev,cur->right);
    }
    bool isValidBST(TreeNode* root) {
        // vector<int> r;
        // int count=0;
        // noofnodes(root,count);
        // cout<<count;
        // inorder(root,r);
        // if(count==r.size())
        //     return true;
        // else return false;
        
        TreeNode* prev=NULL;
        return  check(prev,root);
    }
};
