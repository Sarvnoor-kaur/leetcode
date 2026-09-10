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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        vector<vector<int>>an;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>curr;
            for(int i=0;i<n;i++){
                TreeNode* v=q.front();
                q.pop();
                curr.push_back(v->val);
                if(v->left){
                    q.push(v->left);
                }
                if(v->right){
                    q.push(v->right);
                }
            }
            an.push_back(curr);
        }
        return an;
    }
};