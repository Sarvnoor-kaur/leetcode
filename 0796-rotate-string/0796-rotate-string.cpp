class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }
        string conca=s+s;
        return conca.find(goal)!=string::npos;
        
    }
};