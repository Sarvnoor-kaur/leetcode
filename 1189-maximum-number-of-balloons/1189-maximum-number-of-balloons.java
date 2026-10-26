class Solution {
    public int maxNumberOfBalloons(String text) {
        HashMap<Character,Integer>mp=new HashMap<>();
        mp.put('b',0);
        mp.put('a',0);
        mp.put('l',0);
        mp.put('o',0);
        mp.put('n',0);
        for(int i=0;i<text.length();i++){
            if(mp.containsKey(text.charAt(i))){
                mp.put(text.charAt(i),mp.get(text.charAt(i))+1);
            }
        }
        mp.put('l',mp.get('l')/2);
        mp.put('o',mp.get('o')/2);

        int mini=Integer.MAX_VALUE;
        for(char key:mp.keySet()){
            mini=Math.min(mini,mp.get(key));
        }
        // return mini==Integer.MAX_VALUE?mini:0;
        return mini;
    }
}