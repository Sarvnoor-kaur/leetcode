class Solution {
public:
    int solve(vector<int>& nums, int i, int target, vector<int>& dp) {
        if (i==nums.size() - 1)
            return 0;

        if (dp[i]!=-2)
            return dp[i];

        int ans=-1;

        for (int j=i + 1;j<nums.size(); j++) {
            if (abs(nums[j]-nums[i])<=target) {
                int next = solve(nums, j, target, dp);
                if (next != -1) {
                    ans = max(ans, 1 + next);
                }
            }
        }

        return dp[i] = ans;
    }

    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(), -2); // -2 = uncomputed
        return solve(nums, 0, target, dp);
    }
};