class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>>fi=new ArrayList<>();
        HashMap<String,List<String>>mp=new HashMap<>();
        for(String tr:strs){
            char[]arr=tr.toCharArray();
            Arrays.sort(arr);
            String t=new String(arr);
            mp.putIfAbsent(t,new ArrayList<>());
            mp.get(t).add(tr);
        }
        for(List<String>list:mp.values()){
            fi.add(list);
        }
        return fi;
    }
}