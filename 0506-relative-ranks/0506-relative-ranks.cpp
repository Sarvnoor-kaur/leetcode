class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
    //     int n = score.size();
    //     vector<pair<int, int>> scoreWithIndex;
    
    // // Pair each score with its original index
    //     for (int i = 0; i < n; ++i) {
    //         scoreWithIndex.push_back({score[i], i});
    //     }

    // // Sort scores in descending order
    //     sort(scoreWithIndex.rbegin(), scoreWithIndex.rend());

    // // Prepare the result array with the same size as input
    //     vector<string> result(n);

    // // Assign ranks
    //     for (int i = 0; i < n; ++i) {
    //         if (i == 0) result[scoreWithIndex[i].second] = "Gold Medal";
    //         else if (i == 1) result[scoreWithIndex[i].second] = "Silver Medal";
    //         else if (i == 2) result[scoreWithIndex[i].second] = "Bronze Medal";
    //         else result[scoreWithIndex[i].second] = to_string(i + 1);
    //     }
    //     return result;

        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        int n=score.size();
        for(int i=0;i<score.size();i++){
            pq.push({score[i],i});
        }
        vector<string>ans(n);
        int rank=1;
        while(!pq.empty()){
            auto top=pq.top();
            int sc=top.first;
            int idx=top.second;
            pq.pop();
            
            if(rank==1){
                ans[idx]="Gold Medal";
            }else if(rank==2){
                ans[idx]="Silver Medal";
            }else if(rank==3){
                ans[idx]="Bronze Medal";
            }else{
                ans[idx]=to_string(rank);
            }
            rank++;
        }
        return ans;
        
    }
};  