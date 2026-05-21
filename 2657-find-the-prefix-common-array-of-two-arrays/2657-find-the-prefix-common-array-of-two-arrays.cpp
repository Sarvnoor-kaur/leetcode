class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<bool>se1(n+1,0);
        vector<bool>se2(n+1,0);
        vector<int>re(n);
        int c=0;
        for(int i=0;i<A.size();i++){
            se1[A[i]]=true;
            se2[B[i]]=true;
            if(se2[A[i]]==true){
                c++;
            }
            if(A[i]!=B[i] && se1[B[i]]==true){
                c++;
            }
            re[i]=c;
        }
        return re;
    }
};