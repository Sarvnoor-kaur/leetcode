class Solution {
public:
    int longestContinuousSubstring(string s) {
        int c=1;
        int maxi=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]+1){
                c++;
            }else{
                maxi=max(c,maxi);
                c=1;
            }
        }
        maxi=max(maxi,c);
        return maxi;
        
    }
};