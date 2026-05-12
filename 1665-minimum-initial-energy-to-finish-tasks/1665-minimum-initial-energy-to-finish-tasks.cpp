class Solution {
public:
    bool ispossible(vector<vector<int>>&ta,int va){
        for(auto &t:ta){
            int ac=t[0];
            int min=t[1];
            if(min>va){
                return false;
            }
            va-=ac;
        }
        return true;
    }
    static bool cutom(vector<int>&ta1,vector<int>&ta2){
        int diff1=ta1[1]-ta1[0];
        int diff2=ta2[1]-ta2[0];
        return diff1>diff2;
    } 
    int minimumEffort(vector<vector<int>>& tasks) {
        int n=tasks.size();
        int l=0;
        int r=1e9;
        int re=INT_MAX;
        sort(tasks.begin(),tasks.end(),cutom);
        while(l<=r){
            int mid=l+(r-l)/2;
            if(ispossible(tasks,mid)){
                re=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return re;
    }
};