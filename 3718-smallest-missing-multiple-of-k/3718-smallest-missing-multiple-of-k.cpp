class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>s(nums.begin(),nums.end());
        int i=1,val;
        while(true){
            val=k*i;
            if(s.find(val)==s.end()){
                break;
            }
            i++;
        }
        return val;
        
    }
};