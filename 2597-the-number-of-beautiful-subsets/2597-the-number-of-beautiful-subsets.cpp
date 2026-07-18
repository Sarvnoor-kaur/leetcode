class Solution {
public:
    bool check(vector<int>&temp,int k){
        for(int i=0;i<temp.size();i++){
           for(int j=i+1;j<temp.size();j++){
                if(i!=j && temp[j]-temp[i]==k){
                    return false;
                }
           }
        }
        return true;
    }
    void backtrack(int in,vector<int>&nums,vector<int>&temp,int &count,int k){
        if(in==nums.size()){
            if(!temp.empty() && check(temp,k)){
                count++;
            }
            return ;
        }
        // exclude
        backtrack(in+1,nums,temp,count,k);
        temp.push_back(nums[in]);
        backtrack(in+1,nums,temp,count,k);
        temp.pop_back();

    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        int count=0;
        backtrack(0,nums,temp,count,k);
        return count;
    }
};