class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>an;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.count(target-nums[i])){
                int in=mp[target-nums[i]];
                an.push_back(in);
                an.push_back(i);
                break;
            }
            mp[nums[i]]=i;
            
        }
        return an;
    }
};