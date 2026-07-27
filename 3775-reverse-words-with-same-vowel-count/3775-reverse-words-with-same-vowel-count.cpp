class Solution {
public:
    int count(string word){
        int c=0;
        for(int i=0;i<word.size();i++){
            if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u'){
                c++;
            }
        }
        return c;
    }
    string reverseWords(string s) {
        // string ans=""
        // unordered_map<int,string>mp;
        vector<string>words;
        stringstream ss(s);
        string word;
        while(ss>>word){
            words.push_back(word);
        }
        string ans=words[0];
        int t=count(words[0]);
        for(int i=1;i<words.size();i++){
            if(count(words[i])==t){
                reverse(words[i].begin(),words[i].end());
            }
            ans+=" "+words[i];
        }
        return ans;
    }
};