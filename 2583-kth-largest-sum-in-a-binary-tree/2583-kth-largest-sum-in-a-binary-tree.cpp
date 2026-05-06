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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // priority_queue<pair<int,int>,vector<pair<int,int>>pq;
        priority_queue<long long>pq;
        queue<TreeNode*>q;
        q.push(root);
        // int lev=0;
        while(!q.empty()){
            int z=q.size();
            long long m=0;
            for(int i=0;i<z;i++){
                TreeNode*temp=q.front();
                q.pop();
                m+=temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            pq.push(m);
            // lev++;
        }
        // int ks;
        if(pq.size() < k) return -1;
        for(int i=0;i<k-1;i++){
            pq.pop();
        }
        // return pq.empty()?-1:pq.top();
        return pq.top();
    }
};