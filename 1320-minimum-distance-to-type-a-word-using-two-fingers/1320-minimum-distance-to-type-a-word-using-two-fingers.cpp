#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int getDist(int a, int b) {
        if (a == -1) return 0;
        
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int dfs(string &word, int i, int f1, int f2, vector<vector<vector<int>>> &dp) {
        if (i == word.size()) return 0;

        if (dp[i][f1 + 1][f2 + 1] != -1)
            return dp[i][f1 + 1][f2 + 1];

        int target = word[i] - 'A';

        int useFirst = getDist(f1, target) +
                       dfs(word, i + 1, target, f2, dp);

        int useSecond = getDist(f2, target) +
                        dfs(word, i + 1, f1, target, dp);

        return dp[i][f1 + 1][f2 + 1] = min(useFirst, useSecond);
    }

    int minimumDistance(string word) {
        int n = word.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(27, vector<int>(27, -1))
        );

        return dfs(word, 0, -1, -1, dp);
    }
};