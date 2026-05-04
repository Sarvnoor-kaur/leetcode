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
    TreeNode* make(vector<int>&ve,unordered_map<int,TreeNode*>&mp,unordered_set<int>&ch){

        // TreeNode*root=new TreeNode(ve[0]);
        // if(ve[2]==1){
        //     root->left=new TreeNode(ve[1]);
        // }else{
        //     root->right=new TreeNode(ve[1]);
        // }
        // return root;
        int p=ve[0];
        int child=ve[1];
        int le=ve[2];

        if(mp.find(p)==mp.end()){
            mp[p]=new TreeNode(p);
        }
        if(mp.find(child)==mp.end()){
            mp[child]=new TreeNode(child);
        }
        if(le==1){
            mp[p]->left=mp[child];
        }else{
            mp[p]->right=mp[child];
        }
        ch.insert(child);
        return mp[p];
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mp;
        unordered_set<int>ch;
        for(auto &ve:descriptions){
            make(ve,mp,ch);
        }

        for(auto &p:mp){
            if(ch.find(p.first)==ch.end()){
                return p.second;
            }
        }
        return nullptr;


        
        
    }
};