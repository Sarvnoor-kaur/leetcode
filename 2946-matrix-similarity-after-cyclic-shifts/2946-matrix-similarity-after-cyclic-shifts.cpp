class Solution {
public:
    void left(vector<int>&temp){
        int n = temp.size();
        reverse(temp.begin(), temp.begin()+1);
        reverse(temp.begin()+1, temp.end());
        reverse(temp.begin(), temp.end());
    }
    void right(vector<int>&temp){
        int n = temp.size();
        reverse(temp.begin(), temp.end()-1);
        reverse(temp.end()-1, temp.end());
        reverse(temp.begin(), temp.end());
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>>grid=mat;
        int n=mat[0].size();
        k=k%n;
        while(k!=0){
            int i=0;
            for(auto &vec:grid){
                
                if(i%2==0){
                    left(vec);
                }else{
                    right(vec);
                }
                i++;
            }
            k--;
        }

        return mat==grid?true:false;
    }
};