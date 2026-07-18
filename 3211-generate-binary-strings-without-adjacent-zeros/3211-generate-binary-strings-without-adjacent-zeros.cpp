class Solution {
public:
    void generate(int in,int n,string &te,vector<string>&re){
        if(in==n){
            re.push_back(te);
            return ;
        }
        if(te.empty()|| te.back()!='0'){
            te+='0';
            generate(in+1,n,te,re);
            te.pop_back();
        }
        te+='1';
        generate(in+1,n,te,re);
        te.pop_back();
    }
    vector<string> validStrings(int n) {
        vector<string>re;
        string te="";
        generate(0,n,te,re);
        return re;


    }
};