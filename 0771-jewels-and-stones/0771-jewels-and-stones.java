class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        HashMap<Character,Integer>mp=new HashMap<>();
        for(int i=0;i<stones.length();i++){
            char ch=stones.charAt(i);
            mp.put(ch,mp.getOrDefault(ch,0)+1);
            
        }

        int co=0;
        for(int i=0;i<jewels.length();i++){
            if(mp.containsKey(jewels.charAt(i))){
                co+=mp.get(jewels.charAt(i));
            }
        }
        return co;
    }
}