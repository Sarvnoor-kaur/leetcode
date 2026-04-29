class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int>st;
        int l=0;
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            while(st.find(nums[i])!=st.end()){
                st.erase(nums[l]);
                sum-=nums[l];
                l++;
                
            }
            st.insert(nums[i]);
            sum+=nums[i];
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};