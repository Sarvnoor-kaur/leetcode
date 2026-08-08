class Solution {
    public int maxSubArray(int[] nums) {
        int cu=0;
        int maxi=Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++){
            cu+=nums[i];
            maxi=Math.max(cu,maxi);
            if(cu<0){
                cu=0;
            }
        }
        return maxi;
    }
}