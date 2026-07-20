class Solution {
public:
    int sumsq(int n){
        int um=0;
        while(n>0){
            int dig=n%10;
            um+=(dig*dig);
            n/=10;
        }
        return um;
    }
    bool isHappy(int n) {
        // int num=0;
        unordered_set<int>et;
        while(n!=1 && et.find(n)==et.end()){
            et.insert(n);
            n=sumsq(n);
        }
        return n==1;
        
    }
};