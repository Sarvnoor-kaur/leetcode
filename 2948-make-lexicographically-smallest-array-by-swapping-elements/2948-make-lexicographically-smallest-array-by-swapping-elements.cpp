class Solution {
public:
    int find(int i,vector<int>&parent){
        if(i==parent[i]){
            return parent[i];
        }
        return parent[i]=find(parent[i],parent);
    }
    void unite(int in1,int in2,vector<int>&parent){
        int pa=find(in1,parent);
        int pb=find(in2,parent);
        if(pa!=pb){
            parent[pb]=pa;
        }
    }
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int n=nums.size();
        vector<int>parent(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=1;i<n;i++){
            if(v[i].first-v[i-1].first<=limit){
                int in1=v[i].second;
                int in2=v[i-1].second;
                unite(in1,in2,parent);
            }
        }
        unordered_map<int,vector<int>>gr;
        for(int i=0;i<nums.size();i++){
            int root=find(i,parent);
            gr[root].push_back(i);
        }

        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>pq;
        for(int i=0;i<n;i++){
            int root=find(i,parent);
            pq[root].push(nums[i]);
        }
        for(auto &[r,in]:gr){
            sort(in.begin(),in.end());
            for(int i:in){
                nums[i]=pq[r].top();
                pq[r].pop();
            }
        }
        return nums;
    }
};