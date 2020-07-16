/*
101. Symmetric Tree
Easy

4151

99

Add to List

Share
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
*/

class Solution {
public:
    bool check(TreeNode* l,TreeNode* r) {
        if(l==NULL && r==NULL) return true;
        if(l==NULL || r==NULL) return false;
        //Return True if both are NULL else return false
        //What line 16 checks is only one of them is NULL and the other is not
        //in other words it's equivalent to if( (l==NULL && r!=NULL) || (l!=NULL && r==NULL) )
        
        if(l->val!=r->val) return false;
        return check(l->left,r->right) && check(l->right,r->left);
      //return true;
    }

    bool isSymmetric(TreeNode* root) {
        
        if(root==NULL) return true;
        return check(root->left,root->right);
        
    }
};
