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
    void solve(TreeNode* root,string&small,string path){
        if(!root)return;
        path+=char(root->val + 'a');
        if(root->left==nullptr && root->right==nullptr){
            reverse(path.begin(),path.end());
           if(small==""||path<small){
            small=path;
           }
        }
        
        solve(root->left,small,path);
        solve(root->right,small,path);
        // path.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string small;
        string path="";
        solve(root,small,path);
        return small;
    }
};