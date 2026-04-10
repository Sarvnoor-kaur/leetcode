class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int mini=INT_MAX;
        // unordered_map<int,vector<pair<int,int>>>mp;
        // for(int i=0;i<nums.size();i++){
        //     if(mp.count(nums[i])){
        //         int in=mp[nums[i]].first;
        //         int rem=i-in;
        //         int sum=mp[nums[i]].second+rem;
        //         mp[nums[i]].push_back({i,sum});
        //         // mini=min(mini,i-in);
        //     }else{
        //         mp[nums[i]].push_back({i,i});
        //     }
            
            
        // }
        // for(auto &m:mp)[
        //     if(m.second.second<mini){
        //         mini=m.second.second;
        //     }
        // ]
        // return mini==INT_MAX?-1:mini;
        
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        for(auto &m:mp){
            vector<int>temp=m.second;
            if(temp.size()>=3){
                for(int i=0;i+2<temp.size();i++){
                    int a=temp[i];
                    int b=temp[i+1];
                    int c=temp[i+2];
                    int dis=abs(a-b)+abs(b-c)+abs(c-a);
                    mini=min(mini,dis);
                }
                
            }
            
        }
        return mini==INT_MAX?-1:mini;
    }
};