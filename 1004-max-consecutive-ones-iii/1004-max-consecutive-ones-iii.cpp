class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int n=nums.size();
        int maxi=INT_MIN;
        int z=0;
        for(int r=0;r<n;r++){
            if(nums[r]==0){
                z++;
            }
            while(z>k){
                if(nums[l]==0){
                    z--;
                }
                l++;

            }
            maxi=max(maxi,r-l+1);

        }
        return maxi;
    }
};