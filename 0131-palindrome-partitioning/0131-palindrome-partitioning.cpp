class Solution {
public:
    bool ipalin(string tr){
        int l=0,e=tr.size()-1;
        while(l<e){
            if(tr[l]!=tr[e]){
                return false;
            }
            l++;
            e--;
        }
        return true;
    }
    void part(int i,vector<string>&temp,vector<vector<string>>&fina,string t){
        if(i==t.size()){
            fina.push_back(temp);
            return;
        }
        for(int en=i;en<=t.size();en++){
            string tr=t.substr(i,en-i+1);
            if(ipalin(tr)){
                temp.push_back(tr);
                part(en+1,temp,fina,t);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string t) {
        vector<string>temp;
        vector<vector<string>>fina;
        part(0,temp,fina,t);
        return fina;
    }
};