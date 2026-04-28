class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>t;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            int l=i+1,r=n-1;
            while(l<r){
                int um=nums[i]+nums[l]+nums[r];
                if(um==0){
                    t.insert({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }else if(um<0){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return vector<vector<int>>(t.begin(),t.end());
    }
};