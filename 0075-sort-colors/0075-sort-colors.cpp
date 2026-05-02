class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s=0;
        int mid=0;
        int e=nums.size()-1;
        while(mid<=e){
            if(nums[mid]==0){
                swap(nums[s],nums[mid]);
                mid++;
                s++;
            }else if(nums[mid]==1){
                mid++;
            }else if(nums[mid]==2){
                swap(nums[mid],nums[e]);
                e--;
            }
        }

    }
};