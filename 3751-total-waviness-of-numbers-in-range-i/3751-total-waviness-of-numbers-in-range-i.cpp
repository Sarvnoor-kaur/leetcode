class Solution {
public:
    void wavi(int num,int &c){
        // int la,f;
        vector<int>re;
        if(num == 0) re.push_back(0);
        while(num>0){
            int di=num%10;
            re.push_back(di);
            num/=10;
        }
        // la=re[0];
        // f=re[re.size()-1];
        reverse(re.begin(),re.end());
        for(int i=1;i<re.size()-1;i++){
            if((re[i]>re[i-1] && re[i]>re[i+1])||(re[i]<re[i-1] && re[i]<re[i+1])){
                c++;
            }
        }
    }
    int totalWaviness(int num1, int num2) {
        int w=0;
        for(int i=num1;i<=num2;i++){
            int c=0;
            wavi(i,c);
            w+=c;
            
        }
        return w;

    }
};