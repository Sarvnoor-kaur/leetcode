class Solution {
public:
    bool judgeSquareSum(int c) {
        int l=0,r=sqrt(c);
        while(l<=r){
            long long sum=(long long)l*l+(long long)r*r;
            if(sum==c){
                return true;
            }else if(sum<c){
                l++;
            }else{
                r--;
            }
        }
        return false;

    }
};