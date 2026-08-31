class Solution {
public:
    void backtrack(int in,vector<int>&nums,vector<vector<int>>&an,vector<int>&temp){
        if(in==nums.size()){
            an.push_back(temp);
            return;
        }
        // exclude
        backtrack(in+1,nums,an,temp);
        // exclude
        temp.push_back(nums[in]);

        backtrack(in+1,nums,an,temp);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>an;
        backtrack(0,nums,an,temp);
        return an;
    }
};