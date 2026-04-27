class Solution {
public:
    int zeros(string k ){
        int cz=0;
        for(int i=0;i<k.size();i++){
            if(k[i]=='0'){
                cz++;
            }
        }
        return cz;
    };
    int ones(string t){
        int co=0;
        for(int i=0;i<t.size();i++){
            if(t[i]=='1'){
                co++;
            }
        }
        return co;
    };
    int maxScore(string s) {
        int maxi=0;
        for(int i=1;i<s.size();i++){

            int z=zeros(s.substr(0,i));
            int on=ones(s.substr(i));
            int pl=z+on;
            maxi=max(pl,maxi);
        }
        return maxi;
    }
};