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
        if(root!=nullptr && root->left==nullptr && root->right==nullptr){
            return true;
        }
        return false;
    }
    void path(TreeNode*root,set<string>&an,string tr){
        if(!root) return ;
        if(tr.empty()){
            tr+=to_string(root->val);
        }else{
            tr+="->"+to_string(root->val);
        }
        if(leaf(root)){
            an.insert(tr);
            return;
        }
      
        path(root->left,an,tr);
        path(root->right,an,tr);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        set<string>an;
        string tr="";
        path(root,an,tr);
        vector<string>r(an.begin(),an.end());
        return r;
    }
};