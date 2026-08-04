class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        unordered_set<int>rt(nums.begin(),nums.end());
        vector<int>an;
        for(int i=mini;i<=maxi;i++){
            if(rt.find(i)==rt.end()){
                an.push_back(i);
            }
        }   
        return an;
    }
};