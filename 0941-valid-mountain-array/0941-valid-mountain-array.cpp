class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        vector<int>dec(n,0);
        vector<int>inc(n,0);
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                dec[i]=dec[i-1]+1;
            }
            // else{
            //     dec[i]=dec[i-1]-1;
            // }
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
               inc[i]=inc[i+1]+1; 
            }
        }
        for(int i=1;i<n-1;i++){
            if(dec[i]>0 && inc[i]>0 && inc[i]+dec[i]==n-1){
                return true;
            }
        }
        return false;
        // return dec[n-1]==0;
    }
};