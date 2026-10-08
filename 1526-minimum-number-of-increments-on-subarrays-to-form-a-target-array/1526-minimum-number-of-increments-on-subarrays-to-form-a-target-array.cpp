class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int an=target[0];
        for(int i=1;i<target.size();i++){
            if(target[i]>target[i-1]){
                an+=(target[i]-target[i-1]);
            }

        }
        return an;
    }
};