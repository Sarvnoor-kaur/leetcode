class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int mini=INT_MAX;
        for(auto & m:mp){
            vector<int>temp=m.second;
            if(temp.size()>=3){
                for(int i=0;i+2<temp.size();i++){
                    int a=temp[i];
                    int b=temp[i+1];
                    int c=temp[i+2];
                    int sum=abs(a-b)+abs(a-c)+abs(c-b);
                    mini=min(mini,sum);
                }
            }
        }
        return mini==INT_MAX?-1:mini;
    }
};