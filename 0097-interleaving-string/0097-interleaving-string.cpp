class Solution {
public:
    int leave(int i,int j,string s1, string s2, string s3,vector<vector<int>>&dp){
        int k=i+j;
        if(k==s3.size()){
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int an=false;
        if(i<s1.size() && s1[i]==s3[k]){
            an=leave(i+1,j,s1,s2,s3,dp);
        }
        if(!an && j < s2.size() && s2[j]==s3[k]){
            an=leave(i,j+1,s1,s2,s3,dp);
        }
        return dp[i][j]=an;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int l1=s1.size();
        int l2=s2.size();
        int n=l1+l2;
        if(n!=s3.size()){
            return false;
        }
        // vector<bool>dp(n,false);
         vector<vector<int>> dp(l1 + 1,vector<int>(l2 + 1, -1));
        return leave(0,0,s1,s2,s3,dp);
    }
};