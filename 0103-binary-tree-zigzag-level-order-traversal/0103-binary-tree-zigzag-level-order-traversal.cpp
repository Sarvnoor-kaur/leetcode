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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        vector<vector<int>>re;
        queue<TreeNode*>q;
        q.push(root);
        int l=0;
        while(!q.empty()){
            int n=q.size();
            
            vector<int>curr;
            for(int i=0;i<n;i++){
                TreeNode*temp=q.front();
                curr.push_back(temp->val);
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                
            }

            if(l%2==0){
                re.push_back(curr);
            }else{
                reverse(curr.begin(),curr.end());
                re.push_back(curr);
            }
            l++;

        }
        return re;

    }
};