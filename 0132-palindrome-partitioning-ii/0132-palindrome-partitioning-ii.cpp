class Solution {
public:
    // bool palin(string tr){
    //     int l=0,r=tr.size()-1;
    //     while(l<r){
    //         if(tr[l]!=tr[r]){
    //             return false;
    //         }
    //         l++;
    //         r--;
    //     }
    //     return true;
    // }
    int part(int i,string &t,vector<int>&dp,vector<vector<bool>>&pal){
        if(i==t.size()){
            return -1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int an=INT_MAX;
        for(int e=i;e<t.size();e++){
            // string tr=t.substr(i,e-i+1);
            if(pal[i][e]){
                int cut=1+part(e+1,t,dp,pal);
                an=min(an,cut);
                
            }
        }
        return dp[i]=an;
    }
    int minCut(string t) {
        int n=t.size();
        vector<int>dp(n,-1);
        vector<vector<bool>>pal(t.size(),vector<bool>(n,false));
        for(int i=0;i<n;i++){
            pal[i][i]=true;
        }
        for(int i=0;i<n-1;i++){
            if(t[i]==t[i+1]){
                pal[i][i+1]=true;
            }
        }
        for(int len=3;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(t[i]==t[j] && pal[i+1][j-1]){
                    pal[i][j]=true;
                }
            }
        }
        return part(0,t,dp,pal);

    }
};