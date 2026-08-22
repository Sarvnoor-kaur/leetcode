class Solution {
public:
    bool checkDivisibility(int n) {
        int u=n;
        int um=0;
        int p=1;
        while(n>0){
            int re=n%10;
            um+=re;
            p*=re;
            n/=10;
        }
        int t=um+p;
        return u%t==0;
    }
};