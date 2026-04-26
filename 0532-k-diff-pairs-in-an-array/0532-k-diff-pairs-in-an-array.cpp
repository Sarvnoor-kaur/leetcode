class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) return 0;
        int i=0,j=1,c=0;
        sort(nums.begin(),nums.end());
        while(i<nums.size() && j<nums.size()){
            if(i == j ||nums[j]-nums[i]<k){
                j++;
            }else if(nums[j]-nums[i]>k){
                i++;
            }else{
                c++;
                i++;
                while(i<nums.size()&&nums[i]==nums[i-1]){
                    i++;
                }
            }
        }
        return c;
        
    }
};