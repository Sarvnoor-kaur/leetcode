// class Solution {
//     public int firstUniqChar(String s) {
//         HashMap<Character,Integer>mp=new HashMap<>();
//         for(char ch:s.toCharArray()){
//             if(mp.containsKey(ch)){
//                 mp.put(ch,mp.get(ch)+1);
//             }else{
//                 mp.put(ch,1);
//             }
//         }
//         int i=0;
//         for(char ch:s.toCharArray()){
//             if(mp.get(ch)==1){
//                 return i;
//             }
//             i++;
//         }
//         return -1;
//     }
// }


import java.util.*;

class Solution {
    public int firstUniqChar(String s) {

        HashMap<Character, Integer> map = new HashMap<>();

        // Count frequency
        for (char c : s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        // Find first character whose frequency is 1
        for (int i = 0; i < s.length(); i++) {
            if (map.get(s.charAt(i)) == 1) {
                return i;
            }
        }

        return -1;
    }
}