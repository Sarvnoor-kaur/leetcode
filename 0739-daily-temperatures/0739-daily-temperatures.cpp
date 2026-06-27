class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ngei(n);
        stack<int>st;
        
        // for(int i=n-1;i>=0;i--){
        //     while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
        //         st.pop();
        //     }
        //     if(st.empty()){
        //         ngei[i]=-1;
        //     }else{
        //         ngei[i]=st.top();
        //     }
        //     st.push(i);
        // }
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }
            if(st.empty()){
                ngei[i]=-1;
            }else{
                ngei[i]=st.top();
            }
            st.push(i);

        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(ngei[i]!=-1){
                int val=abs(ngei[i]-i);
                ans.push_back(val);
            }else{
                ans.push_back(0);
            }
        }
        return ans;
        
    }
};