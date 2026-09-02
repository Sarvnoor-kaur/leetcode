class Solution {
    public int countTriplets(int[] num) {
        HashMap<Integer,Integer>mp=new HashMap<>();

        for(int a:num){
            for(int b:num){
                mp.put(a&b,mp.getOrDefault(a&b,0)+1);
            }
        }
        int cnt=0;
        for(int a:num){
            for(int paira:mp.keySet()){
                int fr=mp.get(paira);
                if((a&paira)==0){
                    cnt+=fr;
                }
            }
        }
        return cnt;
    }
}