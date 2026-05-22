class Solution {
public:
    bool ship(vector<int>&weights,int days,int mid){
        int re=1;
        int cw=0;
        for(int &w:weights){
            if(cw+w>mid){
                re++;
                cw=w;
            }else{
                cw+=w;
            }
        }
        return re<=days;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int su=accumulate(weights.begin(),weights.end(),0);

        while(l<=su){
            int mid=l+(su-l)/2;
            if(ship(weights,days,mid)){
                su=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};