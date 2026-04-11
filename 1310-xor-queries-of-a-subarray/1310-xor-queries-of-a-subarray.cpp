class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // vector<int>ans;
        // for(auto &q:queries){
        //     int l=q[0];
        //     int r=q[1];
        //     int x=0;
        //     for(int i=l;i<=r;i++){
        //         x=x^arr[i];
        //     }
        //     ans.push_back(x);
        // }
        // return ans;

        vector<int>pre(arr.size());
        pre[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            pre[i]=pre[i-1]^arr[i];
        }
        vector<int>ans;
        for(auto&q:queries){
            int l=q[0];
            int r=q[1];
            if(l==0){
                ans.push_back(pre[r]);
            }else{
                int xo=pre[l-1]^pre[r];
                ans.push_back(xo);
            }
        }
        return ans;
    }
};