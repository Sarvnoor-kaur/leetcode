class Solution {
    public int maxDepth(String s) {
        int curr=0;
        int maxi=0;
        for(char c:s.toCharArray()){
            if(c=='('){
                curr++;
                maxi=Math.max(maxi,curr);
            }else if(c==')'){
                curr--;
            }
        }
        return maxi;
    }
}