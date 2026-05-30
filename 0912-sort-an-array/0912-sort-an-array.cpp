class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        vector<int>ar;
        while(!pq.empty()){
            int v=pq.top();
            pq.pop();
            ar.push_back(v);
        }
        return ar;
    }
};