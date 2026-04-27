class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int>mp;
        for(int i=0;i<chars.size();i++){
            mp[chars[i]]++;
        }
        int sum=0;
        
        for(auto &an:words){
            unordered_map<char,int>temp=mp;
            bool fl=true;
            for(int i=0;i<an.size();i++){
                
                if(temp[an[i]]>0){
                    temp[an[i]]--;
                }else{
                    fl=false;
                    break;
                }
                
            }
            if(fl){
                sum+=an.size();
            }
        }
        return sum;
    }
};