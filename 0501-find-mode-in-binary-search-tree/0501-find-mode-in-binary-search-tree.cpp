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
    void mode(TreeNode*root,unordered_map<int,int>&mp,int&maxi){
        if(!root)return;
        mp[root->val]++;
        maxi=max(maxi,mp[root->val]);
        mode(root->left,mp,maxi);
        mode(root->right,mp,maxi);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>mp;
        int maxi=0;
        vector<int>re;
        mode(root,mp,maxi);
        for(auto &m:mp){
            if(m.second==maxi){
                re.push_back(m.first);
            }
        }
        
        // re.push_back(maxi);
        return re;
    }
};