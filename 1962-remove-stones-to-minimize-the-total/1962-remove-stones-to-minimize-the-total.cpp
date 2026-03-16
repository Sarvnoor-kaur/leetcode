class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(),piles.end());
        while(k>0){
            int val=pq.top();
            pq.pop();
            int f=ceil((double)val/2);
            pq.push(f);
            k--;
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return accumulate(ans.begin(),ans.end(),0);
    }
};