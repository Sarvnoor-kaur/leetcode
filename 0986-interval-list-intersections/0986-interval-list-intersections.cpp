class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>ans;
        int i=0,j=0;
        if(firstList.size()==0) return ans;
        if(secondList.size()==0) return ans;
        while(i<firstList.size() && j<secondList.size()){
            vector<int>first=firstList[i];
            vector<int>second=secondList[j];
            
            int c1=first[0];
            int n1=first[1];
            int c2=second[0];
            int n2=second[1];
            int val1=max(c1,c2);
            int val2=min(n1,n2);
            
            if(val1<=val2){
                ans.push_back({val1,val2});
            }
            if(n1<n2){
                i++;
            }else{
                j++;
            }
            
        }
        return ans;
    }
    
};