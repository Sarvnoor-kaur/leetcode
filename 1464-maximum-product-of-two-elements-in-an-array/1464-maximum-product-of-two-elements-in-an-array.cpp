class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int v1=nums[n-1]-1;
        int v2=nums[n-2]-1;
        return v1*v2;;
    }
};