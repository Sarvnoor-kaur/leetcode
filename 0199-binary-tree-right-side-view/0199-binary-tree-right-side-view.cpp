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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ri;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* v=q.front();
                q.pop();
                if(i==n-1){
                    ri.push_back(v->val);
                }
                if(v->left){
                    q.push(v->left);
                }
                if(v->right){
                    q.push(v->right);
                }
            }

        }
        return ri;
    }
};