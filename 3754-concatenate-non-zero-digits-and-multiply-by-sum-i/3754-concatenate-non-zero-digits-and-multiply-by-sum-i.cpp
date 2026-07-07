class Solution {
public:
    long long sumAndMultiply(int n) {
        string temp="";
        long long sum=0;
        while(n>0){
            int rem=n%10;
            if(rem!=0){
                sum+=rem;
                temp+=char(rem+'0');
            }
            n/=10;
        }
        reverse(temp.begin(),temp.end());
        if(temp=="") return sum;
        long long num=stoll(temp);
        return num*sum;
    }
};