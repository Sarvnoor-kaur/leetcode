class Solution {
public:
    bool judgeCircle(string moves) {

        int ori=0,orj=0;
        int si=0,sj=0;
        for(int i=0;i<moves.size();i++){
            
            if(moves[i]=='U'){
                si--;
            }else if(moves[i]=='D'){
                si++;
            }else if(moves[i]=='L'){
                sj--;
            }else{
                sj++;
            }
            
        }
        if(si==ori && sj==orj){
            return true;
        }
        return false;
        
    }
};