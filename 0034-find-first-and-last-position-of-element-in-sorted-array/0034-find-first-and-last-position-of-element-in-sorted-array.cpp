class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int fir=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                if(fir==-1){
                    fir=i;
                }
                mp[target]=i;
            }
        }
        // return vector<int>(fir,mp[target]);
        if(fir==-1){
            return {-1,-1};
        }
        return {fir,mp[target]};
    }
};