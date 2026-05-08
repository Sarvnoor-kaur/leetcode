class Solution {
public:

    bool isPrime(int x) {
        if (x < 2) return false;

        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }

        return true;
    }

    vector<int> getPrimeFactors(int x) {

        vector<int> factors;

        for (int p = 2; p * p <= x; p++) {

            if (x % p == 0) {

                factors.push_back(p);

                while (x % p == 0)
                    x /= p;
            }
        }

        if (x > 1)
            factors.push_back(x);

        return factors;
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, vector<int>> divisible;

        // store indices by prime factors
        for (int i = 0; i < n; i++) {

            vector<int> factors = getPrimeFactors(nums[i]);

            for (int p : factors) {
                divisible[p].push_back(i);
            }
        }

        queue<int> q;
        vector<int> dist(n, -1);

        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {

            int i = q.front();
            q.pop();

            if (i == n - 1)
                return dist[i];

            // adjacent left
            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = dist[i] + 1;
                q.push(i - 1);
            }

            // adjacent right
            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = dist[i] + 1;
                q.push(i + 1);
            }

            // teleportation
            if (isPrime(nums[i])) {

                int p = nums[i];

                for (int nxt : divisible[p]) {

                    if (dist[nxt] == -1) {
                        dist[nxt] = dist[i] + 1;
                        q.push(nxt);
                    }
                }

                // important optimization
                divisible[p].clear();
            }
        }

        return -1;
    }
};