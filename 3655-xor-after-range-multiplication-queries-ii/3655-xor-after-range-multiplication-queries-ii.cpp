#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1000000007;

    int power(long long x, long long y) {
        long long res = 1;
        while (y > 0) {
            if (y & 1) {
                res = (res * x) % MOD;
            }
            x = (x * x) % MOD;
            y >>= 1;
        }
        return (int)res;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();
        int T = sqrt(n);

        vector<vector<vector<int>>> groups(T);

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];

            if (k < T) {
                groups[k].push_back({l, r, v});
            } 
            else {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * v) % MOD;
                }
            }
        }

        vector<long long> dif(n + T);

        for (int k = 1; k < T; k++) {

            if (groups[k].empty()) continue;

            fill(dif.begin(), dif.end(), 1);

            for (auto &q : groups[k]) {

                int l = q[0];
                int r = q[1];
                int v = q[2];

                dif[l] = (dif[l] * v) % MOD;

                int R = ((r - l) / k + 1) * k + l;

                dif[R] = (dif[R] * power(v, MOD - 2)) % MOD;
            }

            for (int i = k; i < n; i++) {
                dif[i] = (dif[i] * dif[i - k]) % MOD;
            }

            for (int i = 0; i < n; i++) {
                nums[i] = (1LL * nums[i] * dif[i]) % MOD;
            }
        }

        int res = 0;

        for (int x : nums) {
            res ^= x;
        }

        return res;
    }
};