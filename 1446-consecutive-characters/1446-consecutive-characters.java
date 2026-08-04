class Solution {
    public int maxPower(String s) {
        int cnr=1;
    //     for(char c:s.toCharArray()){
    //         if()
    //     }
        // int maxi=Integer.MIN_VALUE;
        int maxi=1;
        for(int i=1;i<s.length();i++){
            if(s.charAt(i)==s.charAt(i-1)){
                cnr++;
                
            }else{
                cnr=1;
                // maxi=Math.max(cnr,maxi);
            }
            maxi=Math.max(cnr,maxi);
        }
        
        return maxi;
    }
}