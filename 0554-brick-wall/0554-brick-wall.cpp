class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long,int>mp;
        for(auto& w:wall){
            long long s=0;
            for(int i=0;i<w.size()-1;i++){
                s+=w[i];
                mp[s]++;
            }
        }
        int maxi=0;
        for(auto &m:mp){
            if(m.second>maxi){
                maxi=m.second;
            }
        }
        return wall.size()-maxi;
    }
};