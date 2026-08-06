class Solution {
    public boolean isAnagram(String k, String t) {
        if(k.length()!=t.length())return false;
        // char []r=new char[k.length()];
        // char []rr=new char[k.length()];
        // for(char c:k.toCharArray()){
        //     r.add(c);
        // }
        // for(char c:t.toCharArray()){
        //     rr.add(c);
        // }
        char[] a = k.toCharArray();
        char[] b = t.toCharArray();
        Arrays.sort(a);
        Arrays.sort(b);
        return Arrays.equals(a,b);
    }
}