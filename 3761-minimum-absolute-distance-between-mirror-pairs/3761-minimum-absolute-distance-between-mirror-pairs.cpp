class Solution {
public:
    int revers(int val){
        string va=to_string(val);
        reverse(va.begin(),va.end());
        while(va.size() > 1 && va[0] == '0'){
            va.erase(0,1);
        }
        int num=stoi(va);
        return num;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>mp;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
             if(mp.find(nums[i])!=mp.end()){
                mini = min(mini, i-mp[nums[i]]);
            }

            mp[revers(nums[i])] = i;
        }
        return mini==INT_MAX?-1:mini;

    }
};