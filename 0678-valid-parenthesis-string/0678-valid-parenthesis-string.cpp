class Solution {
public:
    int t[101][101];
    bool check(string tr,int open ,int i){
        if(open<0){
            return false;
        }
        if(i==tr.size()){
            if(open==0){
                return true;
            }else{
                return false;
            }
        }
        if(t[open][i]!=-1){
            return t[open][i];
        }

        if(tr[i]=='('){
            return t[open][i]=check(tr,open+1,i+1);
        }else if(tr[i]==')'){
            return t[open][i]=check(tr,open-1,i+1);
        }else{
            bool take=check(tr,open+1,i+1);
            bool nott=check(tr,open-1,i+1);
            bool noth=check(tr,open,i+1);
            return t[open][i]=take||nott||noth;
        }
    }
    bool checkValidString(string tr) {
        memset(t,-1,sizeof(t));
        return check(tr,0,0);
    }
};