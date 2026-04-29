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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // vector<vector<int>>res;
        // if(!root){
        //     return res;
        // }
        // map<int,vector<int>>m;
        // queue<pair<TreeNode*,int>>q;
        // q.push({root,0});
        // while(!q.empty()){
        //     auto[node,col]=q.front();
        //     q.pop();
        //     m[col].push_back(node->val);
        //     if(node->left){
        //         q.push({node->left,col-1});
        //     }
        //     if(node->right){
        //         q.push({node->right,col+1});
        //     }
        // }
        
        // for(auto &[col,nodes]:m){
           
        //     res.push_back(nodes);
        // }
        // return res;

        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        map<int, map<int, multiset<int>>> mp;
        while(!q.empty()){
            TreeNode* f=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            // mp[hd].push_back({});
            mp[col][row].insert({f->val});
            q.pop();

            if(f->left){
                q.push({f->left,{row+1,col-1}});
            }
            if(f->right){
                q.push({f->right,{row+1,col+1}});
            }
        }
        vector<vector<int>>an;
        // for(auto &m:mp){
        //     auto vec=m.second;
        //     sort(vec.begin(),vec.end());
        //     an.push_back(vec);
        // }



         for(auto &m:mp){
            vector<int> vec;
            for(auto &r:m.second){
                vec.insert(vec.end(),r.second.begin(),r.second.end());
            }

            an.push_back(vec);
        }
        return an;
    }
};