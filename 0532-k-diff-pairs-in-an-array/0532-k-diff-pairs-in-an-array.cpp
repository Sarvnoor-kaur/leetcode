class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int c=0;
        if(k==0){
            for(auto &m:mp){
                if(m.second>1){
                    c++;
                }
            }
        }else{
            for(auto& m:mp){
                if(mp.count(m.first+k)){
                    c++;
                }
            }
        }
        return c;
    }
};