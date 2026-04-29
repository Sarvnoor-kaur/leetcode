class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(auto &vec:strs){
            string temp=vec;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(vec);

        }
        for(auto &m:mp){
            auto ve=m.second;
            ans.push_back(ve);
        }
        return ans;
    }
};