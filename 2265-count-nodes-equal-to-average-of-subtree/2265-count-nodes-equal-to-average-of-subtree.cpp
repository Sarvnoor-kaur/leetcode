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
    int find(TreeNode*root){
        
        if(root==nullptr){
            return 0;
        }
        return root->val+find(root->left)+find(root->right);
    }
    int counti(TreeNode*root){
        if(root==nullptr){
            return 0;
        }
        return 1+counti(root->left)+counti(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int c=0;
        int um=find(root);
        int count=counti(root);
        if(root->val==um/count){
            c++;
        }
        c+=averageOfSubtree(root->left);
        c+=averageOfSubtree(root->right);
        return c;
    }
};