class Solution {
public:
    bool mini(vector<int>&nums,int k,int mid){
        int rk=1;
        int c=0;
        for(int &n:nums){
            if(c+n>mid){
                rk++;
                c=n;
            }else{
                c+=n;
            }
        }
        return rk<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        
        int l=*max_element(nums.begin(),nums.end());
        int so=accumulate(nums.begin(),nums.end(),0);

        while(l<=so){
            int mid=l+(so-l)/2;
            if(mini(nums,k,mid)){
                so=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};