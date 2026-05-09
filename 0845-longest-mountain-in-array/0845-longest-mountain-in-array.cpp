class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n= arr.size();
        vector<int>up(n,0);
        vector<int>dow(n,0);
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                up[i]=1+up[i-1];
            }
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                dow[i]=1+dow[i+1];
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
           if(up[i]>0 && dow[i]>0){
                int len=up[i]+dow[i]+1;
                maxi=max(maxi,len);
           }
        }
        return maxi;
    }
};