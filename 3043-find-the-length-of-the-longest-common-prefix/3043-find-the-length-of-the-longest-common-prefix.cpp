class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string>et;
        for(auto &a:arr2){
            string f=to_string(a);
            for(int i=1;i<=f.size();i++){
                string ub=f.substr(0,i);
                et.insert(ub);
            }
        }
        int maxi=0;
        for(auto &m:arr1){
            string mn=to_string(m);
            for(int i=1;i<=mn.size();i++){
                string f=mn.substr(0,i);
                if(et.find(f)!=et.end()){
                   if(f.size()>maxi){
                    maxi=f.size();
                   }
                }
            }
        }
        return maxi;
    }
};
