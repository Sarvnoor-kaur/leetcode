class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                nums[i]=0;
            }else{
                nums[i]=1;
            }
        }
        int s=0,m=0;
        while(m<=nums.size()-1){
            if(nums[m]==0){
                swap(nums[s],nums[m]);
                s++;
                m++;
            }else{
                m++;
            }
        }
        return nums;
    }
};