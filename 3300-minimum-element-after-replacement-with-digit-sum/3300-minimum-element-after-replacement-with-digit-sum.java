class Solution {
    public int getu(int val){
        int um=0;
        while(val>0){
            int dig=val%10;
            um+=dig;
            val=val/10;
        }
        return um;
    }
    public int minElement(int[] nums) {
        ArrayList<Integer>ar=new ArrayList<>();
        for(int i=0;i<nums.length;i++){
            int val=nums[i];
            int an=getu(val);
            ar.add(an);
        }
        return Collections.min(ar);
    }
}