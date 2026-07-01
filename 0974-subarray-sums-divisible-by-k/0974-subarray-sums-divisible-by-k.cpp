class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int total=0;
        unordered_map<int,int>m;
        int presum=0;
        m[0]=1;
        for(int i=0;i<n;i++){
            presum+=nums[i];
            presum=presum%k;
            if(presum<0){
                presum=presum+k;
            }
            if(m.count(presum)){
                total+=m[presum];
                
            }
            m[presum]++;
            

        }
        return total;
    }
};