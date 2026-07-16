class Solution {
public:
    void backtrack(int in,vector<int>&nums,set<vector<int>>&re,vector<int>&temp){
        if(in==nums.size()){
            // ort(temp.begin(),temp)
            re.insert(temp);
            return;
        }
        // exclude
        backtrack(in+1,nums,re,temp);
        temp.push_back(nums[in]);
        backtrack(in+1,nums,re,temp);
        temp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>re;
        sort(nums.begin(),nums.end());
        vector<int>temp;
        backtrack(0,nums,re,temp);
        return vector<vector<int>>(re.begin(),re.end());
    }
};