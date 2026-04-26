class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        if(k < 0) return 0;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0, j = 1;
        int count = 0;

        while(i < n && j < n){

            if(i == j || nums[j] - nums[i] < k){
                j++;
            }
            else if(nums[j] - nums[i] > k){
                i++;
            }
            else{
                count++;
                i++;

                while(i < n && nums[i] == nums[i-1]){
                    i++;
                }
            }
        }

        return count;
    }
};