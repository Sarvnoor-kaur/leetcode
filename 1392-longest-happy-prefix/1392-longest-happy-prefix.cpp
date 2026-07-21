class Solution {
public:
    string longestPrefix(string s) {
        // string rev=s;
        // reverse(rev.begin(),rev.end());
        string comp=s;
        int uf=1;
        int pre=0;
        vector<int>lp(comp.size(),0);
        while(uf<comp.size()){
            if(comp[pre]==comp[uf]){
                lp[uf]=pre+1;
                pre++;
                uf++;
            }else{
                if(pre==0){
                    lp[uf]=0;
                    uf++;
                }else{
                    pre=lp[pre-1];
                }
            }
        }
        int val=lp.back();
        return s.substr(0,val);
    }
};