class Solution {
public:
    void permute(vector<int>&nums,vector<int>&temp,vector<bool>&visited,vector<vector<int>>&ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!visited[i]){
                visited[i]=true;
                temp.push_back(nums[i]);
                permute(nums,temp,visited,ans);
                temp.pop_back();
                visited[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>visited(nums.size(),false);
        vector<int>temp;
        vector<vector<int>>ans;
        permute(nums,temp,visited,ans);
        return ans;
    }
};