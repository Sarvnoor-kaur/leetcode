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
    void inorder(TreeNode*root,vector<int>&result){
        if(root==nullptr){
            return ;
        }
        inorder(root->left,result);
        result.push_back(root->val);
        inorder(root->right,result);
        
    }
    vector<int>inordert(TreeNode*root){
        vector<int>result;
        inorder(root,result);
        return result;
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        ans=inordert(root);
        for(int i=1;i<ans.size();i++){
            if(ans[i]<=ans[i-1]){
                return 0;
            }
        }
        return 1;
        
    }
};