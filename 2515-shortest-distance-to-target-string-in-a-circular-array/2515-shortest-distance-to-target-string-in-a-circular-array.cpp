class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n= words.size();
        int mini=INT_MAX;
        for(int i=0;i<words.size();i++){
            if(words[i]==target){
                int diff = abs(i - startIndex);
                int dist = min(diff, n - diff);
                mini = min(mini, dist);
            }
        }
        return mini==INT_MAX?-1:mini;
    }
};