class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>res;
        vector<int>gpi;
        int temp=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                res.push_back(nums[i]);
            }else if(nums[i]==pivot){
                temp++;
            }else{
                gpi.push_back(nums[i]);
            }
        }
        for(int i=0;i<temp;i++){
            res.push_back(pivot);
        }
        for(int num:gpi){
            res.push_back(num);
        }

        return res;

        
    }
};