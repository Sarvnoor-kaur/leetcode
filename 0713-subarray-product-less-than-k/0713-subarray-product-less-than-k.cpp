class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count=0;
        int start=0,end=0;
        int pro=1;
        while(end<nums.size()){
            pro*=nums[end];
            while(start<=end &&  pro>=k){
                pro/=nums[start];
                start++;
            }
            count+=end-start+1;
            end++;
        }
        return count;
        
    }
};