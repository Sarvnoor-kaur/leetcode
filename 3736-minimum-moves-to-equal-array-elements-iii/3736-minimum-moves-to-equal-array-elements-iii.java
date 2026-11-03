class Solution {
    public int minMoves(int[] nums) {
        int maxi=Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++){
            maxi=Math.max(nums[i],maxi);
        }
        int sum=0;
        for(int i=0;i<nums.length;i++){
            int diff=maxi-nums[i];
            sum+=diff;
        }
        return sum;
    }
}