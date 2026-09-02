class Solution {
    int vowel(String a){
        int c=0;
        for(int i=0;i<a.length();i++){
            if(a.charAt(i)=='a'||a.charAt(i)=='e'||a.charAt(i)=='i'||a.charAt(i)=='o'||a.charAt(i)=='u'){
                c++;
            }
        }
        return c;
    }
    public String reverseWords(String s) {
        String [] word=s.split(" ");
        String an=word[0];
        int count=vowel(word[0]);
        for(int i=1;i<word.length;i++){
            if(vowel(word[i])==count){
                word[i]=new StringBuilder(word[i]).reverse().toString();
                
            }
            an+=" "+word[i];
        }
        return an;
    }
}