class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sm=nums[0];
        int l=nums[nums.size()-1];
        return gcd(l,sm);
    }
};