class Solution {
public:
    int maxVowels(string s, int k) {
        int maxi=0;
        unordered_set<char>vo={'a','e','i','o','u'};
        int cv=0;
        for(int i=0;i<s.size();i++){
            if(vo.count(s[i])){
                cv++;
            }
            if(i>=k && vo.count(s[i-k])){
                cv--;
            }
            maxi=max(maxi,cv);
        }
        return maxi;
    }
};