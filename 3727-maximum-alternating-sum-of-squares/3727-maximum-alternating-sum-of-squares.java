class Solution {
    public long maxAlternatingSum(int[] nums) {
        int n=nums.length;
        long [] rr=new long[n];
        for(int i=0;i<n;i++){
            rr[i]=1L* nums[i]*nums[i];
        }
        Arrays.sort(rr);
        int e=nums.length-1;
        int f=0;
        long um=0;
        while(f<=e){
            um+=rr[e];
            if(f<e){
                um-=rr[f];
                f++;
            }
            e--;
        }
        return um;
    }
}