class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long um=0;
        for(int i=0;i<nums.size();i++){
            long long mini=nums[i];
            long long maxi=nums[i];
            for(int j=i;j<nums.size();j++){
                maxi=max(maxi,(long long)nums[j]);
                mini=min((long long)nums[j],mini);
                long long diff=maxi-mini;
                um+=diff;
            }
        }
        return um;
    }
};