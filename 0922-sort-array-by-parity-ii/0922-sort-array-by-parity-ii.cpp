class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int ev=0;
        int od=1;
        while(ev<nums.size()&& od<nums.size()){
            if(nums[ev]%2==0){
                ev+=2;

            }else if(nums[od]%2==1){
                od+=2;
            }else{
                swap(nums[ev],nums[od]);
                ev+=2;
                od+=2;
            }
        }
        return nums;
    }
};