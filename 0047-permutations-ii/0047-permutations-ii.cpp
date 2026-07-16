class Solution {
public:
    void backtrack(vector<int>&nums,set<vector<int>>&re,vector<int>&temp,vector<bool>&visited){
        if(temp.size()==nums.size()){
            re.insert(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!visited[i]){
                visited[i]=true;
                temp.push_back(nums[i]);
                backtrack(nums,re,temp,visited);
                visited[i]=false;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>re;
        vector<int>temp;
        vector<bool>visited(nums.size(),false);
        backtrack(nums,re,temp,visited);
        return vector<vector<int>>(re.begin(),re.end());
    }
};