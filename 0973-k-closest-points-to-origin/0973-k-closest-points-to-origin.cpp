class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int i=0;
        for(auto &vec:points){
            int x=vec[0];
            int y=vec[1];
            int xval=(x-0)*(x-0);
            int yval=(y-0)*(y-0);
            int plus=xval+yval;
            // int sq=sqrt(plus);
            pq.push({plus,i});
            i++;
        }
        vector<vector<int>>ans;
        while(ans.size()<k){
            auto p=pq.top();
            pq.pop();
            int j=p.second;
            ans.push_back({points[j][0],points[j][1]});
        }
        return ans;
        
    }
};