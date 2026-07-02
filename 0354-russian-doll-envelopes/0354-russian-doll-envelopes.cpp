class Solution {
public:

//    sort by height 
    static bool custom(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),custom);
        // vector<int>dp(envelopes.size(),1);
        vector<int>lis;
        for(int i=0;i<envelopes.size();i++){
            // for(int j=0;j<i;j++){
            //     if(envelopes[i][1]>envelopes[j][1] ){
            //         dp[i]=max(dp[i],dp[j]+1);
            //     }
            // }

            // here i did ki sort by heights with lowerbound
            // lowerbound gives the first greater element from a vlaue
            int h=envelopes[i][1];
            auto it=lower_bound(lis.begin(),lis.end(),h);
            if(it==lis.end()){
                lis.push_back(envelopes[i][1]);
            }else{
                *it=h;
            }
        }
        // return *max_element(dp.begin(),dp.end());
        return lis.size();
    }
};