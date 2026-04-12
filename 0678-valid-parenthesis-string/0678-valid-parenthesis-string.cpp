class Solution {
public:
    int t[101][101];
    bool solve(int i,int open,string s){
        if(open<0)return false;
        // if(s[i]=='('){
        //     st.push('(');
        // }else{
        //     if(s[i]=='*'){
        //         bool take =
        //         bool not take=
        //     }else{
        //         if(st.empty()){
        //             return false;
        //         }else{
        //             st.pop();
        //         }
        //     }
        // }

        if(i==s.size()){
            if(open==0){
                return true;
            }else{
                return false;
            }
        }
        if(t[i][open]!=-1)return t[i][open];
        if(s[i]=='('){
            return t[i][open]=solve(i+1,open+1,s);
        }else if(s[i]==')'){
            return t[i][open]=solve(i+1,open-1,s);
        }else{
            bool takeo=solve(i+1,open+1,s);
            bool takec=solve(i+1,open-1,s);
            bool ntg=solve(i+1,open,s);
            return t[i][open]=takeo||takec||ntg;
        }
    
    }
    bool checkValidString(string s) {
    //    stack<char>st; 

       memset(t,-1,sizeof(t));
       return solve(0,0,s);
    }
};