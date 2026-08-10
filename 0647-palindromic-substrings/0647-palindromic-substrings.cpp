class Solution {
public:
    int countSubstrings(string t) {
        int n=t.size();
        int c=0;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
           dp[i][i]=true;
           c++;
        }
        for(int i=0;i<n-1;i++){
            if(t[i]==t[i+1]){
                dp[i][i+1]=true;
                c++;
            }
        }
        for(int len=3;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(t[i]==t[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                    c++;
                }
            }
        }
        return c;
    }
};