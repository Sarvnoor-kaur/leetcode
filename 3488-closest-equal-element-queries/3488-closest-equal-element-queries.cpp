// class Solution {
// public:
//     vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        
//         int n = nums.size();
//         unordered_map<int, vector<int>> mp;

//         // store indices of each value
//         for(int i=0;i<n;i++){
//             mp[nums[i]].push_back(i);
//         }

//         vector<int> ans;

//         for(int q : queries){

//             int val = nums[q];
//             auto &v = mp[val];

//             if(v.size() == 1){
//                 ans.push_back(-1);
//                 continue;
//             }

//             int res = INT_MAX;

//             for(int idx : v){
//                 if(idx == q) continue;

//                 int diff = abs(idx - q);
//                 int circular = n - diff;

//                 res = min(res, min(diff, circular));
//             }

//             ans.push_back(res);
//         }

//         return ans;
//     }
// };







class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        // store indices
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for(int q : queries){

            int val = nums[q];
            auto &v = mp[val];

            if(v.size() == 1){
                ans.push_back(-1);
                continue;
            }

            // binary search
            int pos = lower_bound(v.begin(), v.end(), q) - v.begin();

            int res = INT_MAX;

            // previous occurrence
            int prev = (pos-1 + v.size()) % v.size();
            int diff = abs(q - v[prev]);
            res = min(res, min(diff, n - diff));

            // next occurrence
            int next = (pos+1) % v.size();
            diff = abs(q - v[next]);
            res = min(res, min(diff, n - diff));

            ans.push_back(res);
        }

        return ans;
    }
};