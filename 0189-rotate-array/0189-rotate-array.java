class Solution {
    public void rotate(int[] nums, int k) {
        
        int [] newarr=new int[nums.length];
         k=k%nums.length;
         int c=nums.length-k;
         int in=0;
        for(int i=c;i<nums.length;i++){
            newarr[in]=nums[i];
            in++;
        }
        for(int i=0;i<c;i++){
            // newarr.append(nums[i]);
            newarr[in]=nums[i];
            in++;
        }
        // return newarr;
        for(int i=0;i<nums.length;i++){
            nums[i]=newarr[i];
        }
    }
}