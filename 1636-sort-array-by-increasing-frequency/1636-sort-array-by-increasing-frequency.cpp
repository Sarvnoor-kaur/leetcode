class Solution {
public:
    static bool custom(pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>>p;
        for(auto &m:mp){
            p.push_back({m.second,m.first});
        }
        sort(p.begin(),p.end(),custom);
        vector<int>re;
        for(auto &c:p){
            int co=c.first;
            int va=c.second;
            re.insert(re.end(),co,va);
        }
        return re;
    }
};