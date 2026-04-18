class Solution {
public:
    int reve(int n){
        int no=0;
        while(n>0){
            int dig=n%10;
            no=no*10+dig;
            n/=10;
        }
        return no;
    }
    int mirrorDistance(int n) {
        int rev=reve(n);
        int ans=abs(n-rev);
        return ans;
    }
};