class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())return 0;
        int maxi=1;
        int length=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                length++;
                maxi=max(length,maxi);
            }else if(nums[i]!=nums[i-1]){
                length=1;
            }

        }
        return maxi;
        
    }
};