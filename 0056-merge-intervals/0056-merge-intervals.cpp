class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>mer;
        sort(intervals.begin(),intervals.end());
        for(auto &interval:intervals){
            if(mer.empty()||mer.back()[1]<interval[0]){
                mer.push_back(interval);
            }else{
                mer.back()[1]=max(mer.back()[1],interval[1]);
            }
        }
        return mer;
        
    }
};