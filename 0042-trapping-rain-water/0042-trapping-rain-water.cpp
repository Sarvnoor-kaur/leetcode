class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>le(n,0);
        vector<int>ri(n,0);
        le[0]=height[0];
        ri[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            le[i]=max(le[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            ri[i]=max(ri[i+1],height[i]);
        }
        int water=0;
        for(int i=0;i<n;i++){
            int va=min(le[i],ri[i])-height[i];
            water+=va;
        }
        return water;

    }
};