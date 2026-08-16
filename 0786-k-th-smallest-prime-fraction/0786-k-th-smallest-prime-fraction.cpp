class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double,pair<int,int>>>mp;
        for(int i=0;i<arr.size()-1;i++){
            for(int j=i;j<arr.size();j++){
                double res=(double)arr[i]/arr[j];
                mp.push_back({res,{arr[i],arr[j]}});
            }
        }
        sort(mp.begin(),mp.end());
        return {mp[k-1].second.first,mp[k-1].second.second};
    }
};