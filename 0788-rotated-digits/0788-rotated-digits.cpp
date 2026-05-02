class Solution {
public:
    bool good(int nu){
        bool ch=false;
        while(nu>0){
            
            int dig=nu%10;
            if(dig==3||dig==4||dig==7){
                return false;
            }
            if(dig==2||dig==5||dig==6||dig==9){
                ch=true;
            }
            nu/=10;
        }
        return ch;
    }
    int rotatedDigits(int n) {
        int co=0;
        for(int i=1;i<=n;i++){
            if(good(i)){
                co++;
            }
        }
        return co;
    }
};