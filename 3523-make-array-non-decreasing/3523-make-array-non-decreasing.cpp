class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        stack<int>st;
        for(auto &num:nums){
            if(!st.empty() && st.top()>num){
                continue;
            }else{
                st.push(num);
            }
        }
        return st.size();
        
    }
};