class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {

        int n = nums.size();

        vector<int> inc(n,1);
        vector<int> dec(n,1);

        // LIS
        for(int i = 1; i < n; i++) {

            for(int j = 0; j < i; j++) {

                if(nums[j] < nums[i]) {

                    inc[i] = max(inc[i], 1 + inc[j]);
                }
            }
        }

        // LDS
        for(int i = n - 1; i >= 0; i--) {

            for(int j = n - 1; j > i; j--) {

                if(nums[i] > nums[j]) {

                    dec[i] = max(dec[i], 1 + dec[j]);
                }
            }
        }

        int maxi = 0;

        for(int i = 0; i < n; i++) {

            if(inc[i] > 1 && dec[i] > 1) {

                maxi = max(maxi, inc[i] + dec[i] - 1);
            }
        }

        return n - maxi;
    }
};