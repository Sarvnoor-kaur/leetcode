class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length()!=t.length()){
            return false;
        }

        char [] arr1=new char[s.length()];
        char [] arr2= new char[t.length()];
        int i=0,j=0;
        for(char c:s.toCharArray()){
            arr1[i]=c;
            i++;
        }
        for(char c:t.toCharArray()){
            arr2[j]=c;
            j++;
        }
        Arrays.sort(arr1);
        Arrays.sort(arr2);
        return Arrays.equals(arr1,arr2);
    }
}