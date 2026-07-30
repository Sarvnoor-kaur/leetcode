class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n=nums.size();
        vector<long long>pre(n);
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pre[i]=pre[i-1]+nums[i];
        }
        vector<int>suff(n);
        suff[n-1]=nums[n-1];
        for(int i=nums.size()-2;i>=0;i--){
            suff[i]=min(suff[i+1],nums[i]);
        }
        long long maxi=LLONG_MIN;
        
        for(int i=0;i<nums.size()-1;i++){
            long long score=pre[i]-suff[i+1];
            maxi=max(maxi,score);
        }
        
        return maxi;
    }
};