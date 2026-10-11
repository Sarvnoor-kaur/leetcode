class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int an=0;
        int i=1;
        // for(int i=1;i<=nums.size();i++){
        //     if(nums.size()%i==0){
        //         an+=(nums[i]*nums[i]);
        //     }
        // }
        for(int num:nums){
            if(nums.size()%i==0){
                an+=(num*num);
                
            }
            i++;
        }
        return an;
    }
};