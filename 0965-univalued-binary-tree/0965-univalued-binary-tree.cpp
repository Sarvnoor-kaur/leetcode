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
    bool check(TreeNode*root,int start){
        if(!root)return true;
        if(root->val!=start){
            return false;
        }
        return check(root->left,start) && check(root->right,start);
     
        
    }
    bool isUnivalTree(TreeNode* root) {
        int start=root->val;
        return check(root,start);

    }
};