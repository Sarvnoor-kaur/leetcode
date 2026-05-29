class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer>et=new HashSet<>();
        for(int num:nums){
            if(et.contains(num)){
                return true;
            }
            et.add(num);
        }
        return false;
    }
}