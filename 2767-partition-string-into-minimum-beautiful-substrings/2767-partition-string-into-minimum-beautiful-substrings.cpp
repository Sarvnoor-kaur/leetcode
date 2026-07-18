class Solution {
public:
    bool power(string &curr){
        int c=curr.size()-1;
        int n=0;
        for(int i=0;i<curr.size();i++){
            
            if(curr[i]=='1'){
                int num=curr[i]-'0';
                int p=pow(2,c);
                int val=num*p;
                n+=val;
            }
            c--;
        }
        if(n<=0){
            return false;
        }
        while(n%5==0){
            n/=5;
        }
        return n==1;
    }
    void backtrack(int in,string &s,vector<string>&temp,int&maxi){
        if(in==s.size()){
            maxi=min(maxi,(int)temp.size());
            return;
        }
        string curr="";
        
        for(int e=in;e<s.size();e++){
            curr+=s[e];
            if(curr[0]=='0'){
                return;
            }
            if(power(curr)){
                temp.push_back(curr);
                backtrack(e+1,s,temp,maxi);
                temp.pop_back();
            }
        } 
    }
    int minimumBeautifulSubstrings(string s) {
        int maxi=INT_MAX;
        vector<string>temp;
        backtrack(0,s,temp,maxi);
        return maxi==INT_MAX?-1:maxi;
    }
};