class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())return true;
        string re="";
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])||isdigit(s[i])){
                re+=tolower(s[i]);
            }
        }
        string temp=re;
        reverse(temp.begin(),temp.end());

        if(temp==re){
            return true;
        }
        return false;
    }
};