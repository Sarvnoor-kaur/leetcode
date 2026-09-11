class Solution {
public:
    void pem(vector<int>nums,vector<int>&temp,vector<bool>&vi,vector<vector<int>>&an){
        if(temp.size()==nums.size()){
            an.push_back(temp);
            return ;
        }

        for(int i=0;i<nums.size();i++){
            if(!vi[i]){
                vi[i]=true;
                temp.push_back(nums[i]);
                pem(nums,temp,vi,an);
                vi[i]=false;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        vector<vector<int>>an;
        vector<bool>vi(n,false);
        pem(nums,temp,vi,an);
        return an;
    }
};