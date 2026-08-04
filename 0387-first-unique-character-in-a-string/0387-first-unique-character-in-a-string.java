class Solution {
    public int firstUniqChar(String s) {
        HashMap<Character,Integer>mp=new HashMap<>();
        for(char ch:s.toCharArray()){
            if(mp.containsKey(ch)){
                mp.put(ch,mp.get(ch)+1);
            }else{
                mp.put(ch,1);
            }
        }
        int i=0;
        for(char ch:s.toCharArray()){
            if(mp.get(ch)==1){
                return i;
            }
            i++;
        }
        return -1;
    }
}