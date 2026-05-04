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
    int findSecondMinimumValue(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int mini=root->val;
        long e=LONG_MAX;

        while(!q.empty()){
            int z=q.size();
            for(int i=0;i<z;i++){
                TreeNode*temp=q.front();
                q.pop();
                
                if(temp->val>mini && temp->val<e){
                    e=temp->val;
                }

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return (e==LONG_MAX)?-1:e;

    }
};