class Solution {
    public int findPairs(int[] nums, int k) {
        HashMap<Integer,Integer>mp=new HashMap<>();
        for(int i=0;i<nums.length;i++){
            if(mp.containsKey(nums[i])){
                mp.put(nums[i],mp.get(nums[i])+1);
            }else{
                mp.put(nums[i],1);
            }
        }
        int c=0;
        if(k==0){
            for(int ke:mp.keySet()){
                if(mp.get(ke)>1){
                    c++;
                }
            }
       }else{
            for(int ke:mp.keySet()){
                if(mp.containsKey(ke+k)){
                    c++;
                }
            }
       }
       return c;
    }
}