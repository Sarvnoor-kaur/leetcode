class Solution {
public:
    bool partition(vector<int>&nums,int k,vector<int>&part,int tar,int in){
        if(in==nums.size()){
            for(auto &n:part){
                if(n!=tar){
                    return false;
                }
            }
            return true;
        }
        int val=nums[in];
        for(int i=0;i<part.size();i++){
            if(part[i]+val<=tar){
                part[i]+=val;
                if(partition(nums,k,part,tar,in+1)){
                    return true;
                }
                part[i]-=val;
                if(part[i] == 0)
                    break;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int um=accumulate(nums.begin(),nums.end(),0);
        if(um%k!=0)return false;
        int tar=um/k;
        vector<int>part(k,0);
        return partition(nums,k,part,tar,0);
    }
};