class Solution {
    public String findroot(String wo,HashSet<String>et){
        for(int i=0;i<wo.length();i++){
            String roo=wo.substring(0,i);
            if(et.contains(roo)){
                return roo;
            }
        }
        return wo;
    }
    public String replaceWords(List<String> dictionary, String sentence) {
        HashSet<String>et=new HashSet<>(dictionary);
        String[]word=sentence.split(" ");
        StringBuilder up=new StringBuilder();
        for(String wo:word){
            up.append(findroot(wo,et)).append(" ");
        }
        up.deleteCharAt(up.length()-1);
        return up.toString();

    }
}