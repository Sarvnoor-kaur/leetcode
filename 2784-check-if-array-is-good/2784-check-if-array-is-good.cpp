class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int maxi=INT_MIN;
        for(auto &m:mp){
            if(maxi<m.first){
                maxi=m.first;
            }
        }
        if(nums.size()!=maxi+1){
            return false;
        }
        // for(auto &m:mp){
        //     if(m.first==maxi){
        //         if(m.second!=2){
        //             return false;
        //         }
        //     }
        // }

        for(int i=1;i<maxi;i++){
            if(mp[i]!=1){
                return false;
            }
        }
        return mp[maxi]==2;
        
    }
};