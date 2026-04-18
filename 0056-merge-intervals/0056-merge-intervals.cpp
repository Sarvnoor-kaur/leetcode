class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>merge;
        sort(intervals.begin(),intervals.end());
        
        for(auto interval:intervals){
            if(merge.empty()||merge.back()[1]<interval[0]){
                merge.push_back(interval);
            }else{
                merge.back()[1]=max(merge.back()[1],interval[1]);
            }
        }
        return merge;
        
    }
};