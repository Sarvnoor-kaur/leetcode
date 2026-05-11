class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>arr;
        for(auto num:nums){
            string t=to_string(num);
            for(int i=0;i<t.size();i++){
                int val=t[i]-'0';
                arr.push_back(val);
            } 
        }
        return arr;
    }
};