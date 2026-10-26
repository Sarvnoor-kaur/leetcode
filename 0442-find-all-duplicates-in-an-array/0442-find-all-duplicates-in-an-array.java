class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        HashMap<Integer,Integer>mp= new HashMap<>();
        for(int i=0;i<nums.length;i++){
            if(mp.containsKey(nums[i])){
                mp.put(nums[i],mp.get(nums[i])+1);
            }else{
                mp.put(nums[i],1);
            }
        }
        List<Integer>li=new ArrayList<>();
        
        for(int key:mp.keySet()){
            if(mp.get(key)==2){
                li.add(key);
            }
        }
        return li;
    }
}