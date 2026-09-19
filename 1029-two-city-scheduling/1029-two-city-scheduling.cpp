class Solution {
public:
    static bool custom(vector<int>&a,vector<int>&b){
        return (a[0]-a[1])<(b[0]-b[1]);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),custom);
        int an=0;
        int n=costs.size()/2;

        for(int i=0;i<n;i++){
            an+=costs[i][0];
        }
        for(int i=n;i<2*n;i++){
            an+=costs[i][1];
        }
        return an;
    }
};