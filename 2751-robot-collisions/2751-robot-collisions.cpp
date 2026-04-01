#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        vector<int> idx(n);
        for(int i = 0; i < n; i++) idx[i] = i;
        
        // sort indices by position
        sort(idx.begin(), idx.end(), [&](int a, int b){
            return positions[a] < positions[b];
        });
        
        stack<int> st;
        
        for(int id : idx){
            if(directions[id] == 'R'){
                st.push(id);
            }
            else{
                while(!st.empty() && healths[id] > 0){
                    int top = st.top();
                    
                    if(healths[top] < healths[id]){
                        st.pop();
                        healths[id]--;
                        healths[top] = 0;
                    }
                    else if(healths[top] == healths[id]){
                        st.pop();
                        healths[top] = 0;
                        healths[id] = 0;
                        break;
                    }
                    else{
                        healths[top]--;
                        healths[id] = 0;
                        break;
                    }
                }
            }
        }
        
        vector<int> result;
        for(int i = 0; i < n; i++){
            if(healths[i] > 0)
                result.push_back(healths[i]);
        }
        
        return result;
    }
};