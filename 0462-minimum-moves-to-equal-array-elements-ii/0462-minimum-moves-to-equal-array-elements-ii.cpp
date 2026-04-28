class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid;
        int n=nums.size();
        mid=nums[n/2];
        int count=0;
        int add;
        for(int i=0;i<=n-1;i++){
            add=abs(mid-nums[i]);
            count+=add;
        }
        return count;
        // int sum=accumulate(nums.begin(),nums.end(),0);
        // int mini=*min_element(nums.begin(),nums.end());

        // return sum-(nums.size()*mini);
        
    }
};