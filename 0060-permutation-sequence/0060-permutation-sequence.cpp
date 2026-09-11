class Solution {
public:
    string getPermutation(int n, int k) {
        string tr="";
        for(int i=1;i<=n;i++){
            tr+=to_string(i);
        }
        // string n;
        while(k>1){
            next_permutation(tr.begin(),tr.end());
            k--;
        }
        return tr;
    }
};