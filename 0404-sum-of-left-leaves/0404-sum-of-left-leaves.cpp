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
    bool leaf(TreeNode*root){
        if(root->left==nullptr && root->right==nullptr && root!=nullptr){
            return true;
        }
        return false;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int um=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            
                TreeNode*v=q.front();
                q.pop();
                if (v->left != nullptr && leaf(v->left)) {
                    um += v->left->val;
                }
                if(v->left){
                    q.push(v->left);
                }
                if(v->right){
                    q.push(v->right);
                }
            

        }
        return um;
    }
};