class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int num =0;
        int um=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]+1){
                um+=nums[i];
            }else{
                break;
            }
        }
        int val=0;
        while(true){
            if(find(nums.begin(),nums.end(),um)==nums.end()){
                // return um;
                val=um;
                break;
            }
            um++;
        }
        return val;
        
    }
};