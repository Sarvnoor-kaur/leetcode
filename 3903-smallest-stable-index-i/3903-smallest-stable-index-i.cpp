class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> minIdx(n);
        minIdx[n-1] = n-1;
        for (int i=n-2;i>=0;i--) {
            if (nums[i] < nums[minIdx[i+1]]) minIdx[i] = i;
            else minIdx[i] = minIdx[i+1];
        }
        int maxIdx = 0;
        for (int i=0;i<n;i++) {
            if (nums[i] > nums[maxIdx]) maxIdx = i;
            if (nums[maxIdx] - nums[minIdx[i]] <= k) return i;
        }
        return -1;
    }
};