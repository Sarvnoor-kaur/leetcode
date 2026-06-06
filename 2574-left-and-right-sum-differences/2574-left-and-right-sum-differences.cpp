class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        vector<int>pre(n);
        vector<int>suff(n);
        pre[0]=0;
        suff[n-1]=0;
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i-1];
        }

        for(int i=n-2;i>=0;i--){
            suff[i]=suff[i+1]+nums[i+1];
        }

        for(int i=0;i<n;i++){
            int dif=abs(suff[i]-pre[i]);
            ans.push_back(dif);
        }
        return ans;
       
    }
};