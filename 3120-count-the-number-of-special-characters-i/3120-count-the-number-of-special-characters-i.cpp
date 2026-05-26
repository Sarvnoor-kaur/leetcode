class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char>s1;
        set<char>s2;
        for(int i=0;i<word.size();i++){
            if(islower(word[i])){
                s2.insert(word[i]);
            }else{
                s1.insert(word[i]);
            }
        }
        int count=0;
        for(auto c:s2){
            if(s1.find(toupper(c))!=s1.end()){
                count++;
            }
        }
        return count;
    }
};