class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        stack<int>st;
        for(auto &num:nums2){
            while(!st.empty()  && st.top()<num){
                mp[st.top()]=num;
                st.pop();
            }
            st.push(num);
        }
        while(!st.empty()){
            mp[st.top()]=-1;
            st.pop();
        }

        vector<int>ans;
        for(auto &num:nums1){
            ans.push_back(mp[num]);
        }
        return ans;
    }
};