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
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>re;
       
        while(!q.empty()){
            int a=q.size();
            vector<int>curr;
            for(int i=0;i<a;i++){
                TreeNode* va=q.front();
                curr.push_back(va->val);
                q.pop();
                if(va->left){
                    q.push(va->left);
                }
                if(va->right){
                    q.push(va->right);
                }

            }
            re.push_back(curr);
        }
        return re;
    }
};