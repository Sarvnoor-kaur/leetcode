class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>t;
        int co=0;
        // for(int i=0;i<s.size();i++){
        //     if(t.empty()){
        //         t.push(s[i]);
        //     }else{
        //         if(s[i]=='a' && t.top()=='b'){
        //             c++;
        //             continue;
                    
        //         }else {
        //             t.push(s[i]);
        //         }
        //     }
            
        // }
        // return c;

        for(char c:s){
            if(c=='b'){
                t.push('b');
            }else{
                if(!t.empty()){
                    t.pop();
                    co++;
                }
            }
        }
        return co;
    }
};