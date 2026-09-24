class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>>res;
        int n= nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int p=j+1,q=n-1;
                while(p<q){
                    long long sum=(long long)nums[i]+(long long)nums[j]+
                                    (long long)nums[p]+(long long)nums[q];
                    if(sum<target){
                            p++;
                    }else if(sum>target){
                        q--;
                    }else{
                        res.insert({nums[i],nums[j],nums[p],nums[q]});
                        p++;
                        q--;
                    }
                }
            }
        }
        return vector<vector<int>>(res.begin(),res.end());
        
    }
};