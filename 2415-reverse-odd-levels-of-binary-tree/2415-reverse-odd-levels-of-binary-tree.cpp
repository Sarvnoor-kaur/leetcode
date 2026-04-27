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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        int l=0;
        queue<TreeNode*>q;
        q.push(root);
        // vector<int>an;
        while(!q.empty()){
            int n=q.size();
            vector<TreeNode*>node;
            vector<int>cu;
            for(int i=0;i<n;i++){
                TreeNode*temp=q.front();
                q.pop();
                node.push_back(temp);
                cu.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            if(l%2!=0){
                reverse(cu.begin(),cu.end());
                for(int i=0;i<n;i++){
                    node[i]->val=cu[i];
                }
            }
            
            l++;
        }
        return root;

    }
};