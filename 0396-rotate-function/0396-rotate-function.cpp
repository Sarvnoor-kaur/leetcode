class Solution {
public:
    void rotate(vector<int>&nums){
        int n = nums.size();
        if (n <= 1) return;
        int last = nums[n-1];
        for(int i = n-1; i > 0; i--){
            nums[i] = nums[i-1];
        }
        nums[0] = last;
    }
    int maxRotateFunction(vector<int>& nums) {
        // int maxi=INT_MIN;
        // int sum=0;
        // for(int i=0;i<nums.size();i++){
        //     sum+=i*nums[i];
        // }
        // maxi=max(sum,maxi);
        // int end=nums.size()-1;
        // while(end>0){
        //     int i=0;
            
        // }

        // int maxi;
        int n=nums.size();
        int j=1;
        int f0=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            f0+=i*nums[i];
        }
        // maxi=sum;
        // while(j<=ro){
        //     rotate(nums);
        //     sum=0;
        //     for(int i=0;i<nums.size();i++){
        //         sum+=i*nums[i];
        //     }
        //     maxi=max(sum,maxi);
            
        //     j++;
        // }

        // return maxi;

        long maxi = f0;
        long curr = f0;
        
        
        for(int k = 1; k < n; k++){
            curr = curr + sum - (long)n * nums[n - k];
            maxi = max(maxi, curr);
        }
        
        return maxi;
        
    }
};