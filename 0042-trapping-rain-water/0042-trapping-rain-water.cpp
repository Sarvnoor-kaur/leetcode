class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>lm(n,0);
        vector<int>rm(n,0);
        lm[0]=height[0];
        rm[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            lm[i]=max(lm[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            rm[i]=max(rm[i+1],height[i]);
        }
        int w=0;
        for(int i=0;i<n;i++){
            int dif=min(rm[i],lm[i])-height[i];
            w+=dif;
        }
        return w;
    }
};