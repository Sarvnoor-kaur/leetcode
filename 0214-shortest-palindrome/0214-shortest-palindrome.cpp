class Solution {
public:
    string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        int pre=0;
        int suff=1;
        string comp=s+"#"+rev;
        vector<int>lp(comp.size(),0);
        while(suff<comp.size()){
            if(comp[suff]==comp[pre]){
                lp[suff]=pre+1;
                pre++;
                suff++;
            }else{
                if(pre==0){
                    lp[suff]=0;
                    suff++;
                }else{
                    pre=lp[pre-1];
                }
            }
        }
        int v=lp.back();
        string rem=s.substr(v);
        reverse(rem.begin(),rem.end());
        return rem+s;
    }
};