class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    result.push_back(nums1[i]);
                    break;
                }
            }
        }
        unordered_set<int>num(result.begin(),result.end());
        vector<int>res;
        for(int val:num){
            res.push_back(val);
        }
        return res;
        
    }
};