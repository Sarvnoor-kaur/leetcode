class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<=1)return 0;
        int diff=nums[1]-nums[0];
        int c=1;
        int maxi=0;
        for(int i=2;i<nums.size();i++){
            int di=nums[i]-nums[i-1];
            if(di==diff){
                c++;
                 maxi += (c - 1); 
            }else{
                diff=di;
                c=1;
            }
        }
        return maxi;
        
    }
};