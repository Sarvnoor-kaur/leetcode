class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int total=0;
        unordered_map<int,int>m;
        int presum=0,rem;
        m[0]=1;
        for(int i=0;i<n;i++){
            presum+=nums[i];
            rem=presum%k;
            if(rem<0){
                rem=rem+k;
            }
            if(m.count(rem)){
                total+=m[rem];
                
            }
            m[rem]++;
            

        }
        return total;
    }
};