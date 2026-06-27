class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int>left(nums.size(),0);
        vector<int>right(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                left[i]=(i==0?1:left[i-1]+1);
            }
        }
         for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==1){
                right[i]=(i==nums.size()-1?1:right[i+1]+1);
            }
        }
        int maxi=0;
        bool zero=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zero=true;
                int l=(i>0)?left[i-1]:0;
                int r=(i<nums.size()-1)?right[i+1]:0;
                int val=l+r;
                maxi=max(maxi,val);
            }
        }
        if(!zero){

            return nums.size()-1;
        }
        return maxi;


    }
};