class Solution {
public:
    void gen(int n ,vector<string>&v,string &re,int o,int c){
        if(re.size()==2*n){
            v.push_back(re);
            return;
        }
        if(o<n){
            re.push_back('(');
            gen(n,v,re,o+1,c);
            re.pop_back();
        }
        if(c<o){
            re.push_back(')');
            gen(n,v,re,o,c+1);
            re.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        string re="";
        gen(n,v,re,0,0);
        return v;
    }
};