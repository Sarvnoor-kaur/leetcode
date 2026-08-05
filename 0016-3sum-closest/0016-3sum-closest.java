class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int n=nums.length;
        int mini=Integer.MAX_VALUE;
        int clo=0;
        for(int i=0;i<n-2;i++){
            int curr=nums[i];
            int l=i+1;
            int r=n-1;
            while(l<r){
                int um=curr+nums[l]+nums[r];
                int diff=Math.abs(target-um);
                // mini=Math.min(mini,diff);
                if(mini>diff){
                    mini=diff;
                    clo=um;
                }
                if(um<target){
                    l++;
                }else if(um>target){
                    r--;
                }else{
                    return um;
                }
            }
        }
        return clo;
    }
}