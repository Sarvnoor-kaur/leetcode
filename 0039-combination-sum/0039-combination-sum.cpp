class Solution {
public:
    void subset(vector<int>&arr,int index,int n,int target,vector<int>temp,vector<vector<int>>&ans){
        
        if(index==n){
            int sum=accumulate(temp.begin(),temp.end(),0);
            if(sum==target){
                ans.push_back(temp);
            }
            return ;
        }
        //not include 
        subset(arr,index+1,n,target,temp,ans);
        temp.push_back(arr[index]);
        subset(arr,index,n,target,temp,ans);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        subset(candidates,0,candidates.size(),target,temp,ans);
        return ans;

    }
};