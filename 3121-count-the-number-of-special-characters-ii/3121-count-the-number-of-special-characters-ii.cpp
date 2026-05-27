class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>mp;
        for(int i=0;i<word.size();i++){
            if(isupper(word[i]) && mp.find(word[i]) == mp.end()) {
                mp[word[i]] = i;       
            } else if(islower(word[i])) {
                mp[word[i]] = i;     
            }
            // mp[word[i]]=i;
        }
        set<char>s1;
        for(int i=0;i<word.size();i++){
            if(islower(word[i])){
                s1.insert(word[i]);
            }
        }
        int count=0;
        for(char c:s1){
            if(mp.find(toupper(c))!=mp.end() && mp[c]<mp[toupper(c)]){
                count++;
            }
        }
        return count;

        
        

    }
};