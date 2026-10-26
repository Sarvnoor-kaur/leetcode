class Solution {
    public int firstUniqChar(String s) {

        HashMap<Character,Integer>mp= new HashMap<>();
        for(char c:s.toCharArray()){
            if(mp.containsKey(c)){
                mp.put(c,mp.get(c)+1);
            }else{
                mp.put(c,1);
            }
        } 
        int i=0;
        for(char c:s.toCharArray()){
            if(mp.get(c)==1){
                return i;
            }
            i++;
        }       
        return -1;
    }
}