class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long>sq;
        for(int i=0;i<nums.size();i++){
            int val= 1LL*nums[i]*nums[i];
            sq.push_back(val);
        }
        sort(sq.begin(),sq.end());
        int s=0;
        int e=nums.size()-1;
        long long sum = 0;
        while(s<=e){
            sum+=sq[e];
            if(s<e){
                sum-=sq[s];
                s++;
            }
            e--;
        }
        return sum;
    }
};