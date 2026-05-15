class Solution {
public:
    int findMin(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // return nums[0];
        int l=0,r=nums.size()-1;
        while(l<r){
            int mi=(l+r)/2;
            if(nums[mi]>nums[r]){
                l=mi+1;
            }else if(nums[mi]>nums[r]){
                r=mi;
            }else{
                r--;
            }
        }
        return nums[l];
    }
};