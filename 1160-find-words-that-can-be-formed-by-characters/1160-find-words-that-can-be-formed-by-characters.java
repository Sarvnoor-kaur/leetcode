class Solution {
    public int countCharacters(String[] words, String chars) {
        HashMap<Character,Integer>mp=new HashMap<>();
        for(char c:chars.toCharArray()){
            if(mp.containsKey(c)){
                mp.put(c,mp.get(c)+1);
            }else{
                mp.put(c,1);
            }
        }
        int len=0;
        for(String w:words){
            HashMap<Character,Integer>temp=new HashMap<>(mp);
            boolean flag=true;
            for(int i=0;i<w.length();i++){             
                char ch = w.charAt(i);
                if(temp.getOrDefault(ch, 0) > 0){
                    temp.put(ch,temp.get(ch)-1);

                }else{
                    flag=false;
                    break;
                }
            }
            if(flag){
                len+=w.length();
            }
        }
        return len;
    }
}