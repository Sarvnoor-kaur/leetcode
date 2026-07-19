class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int,int>mp;
        long long um=0;
        for(int i=0;i<2;i++){
            um+=nums[i];
        }
        mp[um]++;
        for(int i=2;i<nums.size();i++){
            um+=nums[i];
            um-=nums[i-2];
            if(mp.count(um)){
                return true;
            }
            mp[um]++;
        }
        return false;
    }
};