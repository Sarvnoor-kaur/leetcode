class Solution {
    public String longestPalindrome(String s) {
        int n=s.length();
        if(n==0)return "";
        int t=0;
        int maxi=1;
        boolean [][]dp=new boolean [n][n];
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for(int i=0;i<n-1;i++){
            if(s.charAt(i)==s.charAt(i+1)){
                dp[i][i+1]=true;
                t=i;
                maxi=2;
            }
        }
        for(int len=3;len<=n;len++){
            int e=n-len;
            for(int i=0;i<=e;i++){
                int j=i+len-1;
                if(s.charAt(i)==s.charAt(j) && dp[i+1][j-1]){
                    dp[i][j]=true;
                    t=i;
                    maxi=len;
                }
            }
        }
        return s.substring(t,t+maxi);
    }
}