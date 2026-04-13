class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long,int>mp;
        for(auto &vec:wall){
            // vector<int>temp(vec.size());
            // temp[0]=vec[0];
            // mp[temp[0]]++;
            long long s=0;
            // for(int i=1;i<vec.size()-1;i++){
            //     temp[i]=temp[i-1]+vec[i];
            //     mp[temp[i]]++;

            // }

            for(int i=0;i<vec.size()-1;i++){
                s+=vec[i];
                mp[s]++;
            }
            
        }
        int maxi=0;
        for(auto &m:mp){
            if(m.second>maxi){
                maxi=m.second;
            }
        }
        return wall.size()-maxi;
        
    }
};