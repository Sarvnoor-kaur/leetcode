class Solution {
public:
    // static bool custom(string&a,string&b){
    //     return a+b>b+a;
    // }
    long long smallestNumber(long long num) {
        long long temp = llabs(num);
        if(num==0)return 0;
        vector<int>ct;
        while(temp>0){
            int dig=temp%10;
            ct.push_back(dig);
            temp/=10;
        }
        if(num<0){
            sort(ct.begin(),ct.end(),greater<int>());
        }else{
            sort(ct.begin(),ct.end());
        }
        
        int j=1;
        if(ct[0]==0){
            while(j<ct.size()&&ct[j]==0){
                j++;
            }
            if(j < ct.size()){
                swap(ct[0], ct[j]);
            }
        }
        long long an=0;
        for(int d:ct){
            an=an*10+d;
        }
        if(num<0){
            an=-(an);
        }
        return an;
        
    }
};