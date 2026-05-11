/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        string an="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*temp=q.front();
            q.pop();
            if(temp==nullptr){
                an+="null,";
                continue;
            }
            an+=to_string(temp->val)+",";
            q.push(temp->left);
            q.push(temp->right);
        }
        return an;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()){
            return nullptr;
        }
        stringstream ss(data);
        string it;
        getline(ss,it,',');
        TreeNode*root=new TreeNode(stoi(it));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*temp=q.front();
            q.pop();
            if(!getline(ss,it,','))break;
            if(it!="null"){
                temp->left=new TreeNode(stoi(it));
                q.push(temp->left);
            }
            if(!getline(ss,it,','))break;
            if(it!="null"){
                temp->right=new TreeNode(stoi(it));
                q.push(temp->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));