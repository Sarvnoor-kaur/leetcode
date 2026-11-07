class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int i=1;
        // if(find(nums.i)!=nums.end()){
        //     return i;
        // }
        // for(int i=1;i<nums.size();i++){
        //     if(nums[i-1]==nums[i]-1){
        //         continue;
        //     }else{
        //         return nums[i]+1;
        //     }
        // }
        sort(nums.begin(), nums.end());
        
        int i = 1; 
        
        for (int num : nums) {
            
            if (num == i) {
                i++; 
            }
        }
        
        return i; 
    
    }
};