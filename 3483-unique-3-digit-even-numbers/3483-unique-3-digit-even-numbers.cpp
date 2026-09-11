class Solution {
public:
    void total(vector<int>& digits,vector<bool>&ued,unordered_set<string>&rt,string &tr){
        if(tr.size()==3){
            if(tr[0]!='0' && ((tr[2]-'0')%2==0)){
                rt.insert(tr);
                
            }
            return;
        }
        for(int i=0;i<digits.size();i++){
            if(ued[i]==false){
                ued[i]=true;
                tr.push_back(digits[i]+'0');
                total(digits,ued,rt,tr);
                ued[i]=false;
                tr.pop_back();
            }
        }
    }
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        vector<bool>ued(n,false);
        unordered_set<string>rt;
        string tr="";
        total(digits,ued,rt,tr);
        return rt.size();
    }
};