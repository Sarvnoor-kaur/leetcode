class Solution {
public:
    vector<string>keypad={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void gen(int in,string digits,string&temp,vector<string>&re){
        if(digits.size()==temp.size()){
            re.push_back(temp);
            return;
        }
        int dig=digits[in]-'0';
        string va=keypad[dig];
        for(int i=0;i<va.size();i++){
            temp+=va[i];
            gen(in+1,digits,temp,re);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>re;
        if(digits.empty())return re;
        string temp="";
        gen(0,digits,temp,re);

        return re;
    }
};