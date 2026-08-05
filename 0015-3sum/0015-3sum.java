class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        Set<List<Integer>>et=new HashSet<>();
        int n=nums.length;
        for(int i=0;i<n-2;i++){
            int curr=nums[i];
            int l=i+1;
            int r=n-1;
            while(l<r){
                int nu=curr+nums[l]+nums[r];
                if(nu==0){
                    et.add(Arrays.asList(curr,nums[l],nums[r]));
                    l++;
                    r--;
                }else if(nu<0){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return new ArrayList<>(et);
    }
}