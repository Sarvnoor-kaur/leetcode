class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0;
        int len=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>k){
                while(mp[nums[i]]>k){
                    mp[nums[l]]--;
                    if(mp[nums[l]]==0){
                        mp.erase(nums[l]);
                    }
                    l++;
                }
            }
            len=max(len,i-l+1);
        }
        return len;
    }
};