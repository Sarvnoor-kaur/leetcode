class Solution {
public:
    void dfs(string jf,unordered_map<string,priority_queue<string,vector<string>,greater<string>>>&pq,vector<string>&an){
        while(!pq[jf].empty()){
            string ne=pq[jf].top();
            pq[jf].pop();
            dfs(ne,pq,an);
        }
        an.push_back(jf);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,priority_queue<string,vector<string>,greater<string>>>pq;
        for(auto&t:tickets){
            string from=t[0];
            string to=t[1];
            pq[from].push(to);
        }
        vector<string>an;
        dfs("JFK",pq,an);
        reverse(an.begin(),an.end());
        return an;

    }
};