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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        int level=1;
        int ml;
        q.push(root);
        int maxi=INT_MIN;
        while(!q.empty()){
            int z=q.size();
            int sum=0;
           
            for(int i=0;i<z;i++){
                TreeNode*temp=q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            if(maxi<sum){
                maxi=sum;
                ml=level;
            }
            level++;
            

        }
        return ml;
    }
};