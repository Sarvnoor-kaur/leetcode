class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // int count=0;
        // set<int>an;
        // sort(meetings.begin(),meetings.end());
        // for(auto vec:meetings){
        //     int s=vec[0];
        //     int e=vec[1];
        //     for(int i=s;i<=e;i++){
        //         an.insert(i);
        //     }
        // }
        // if(an.size()>0){
        //     count=days-an.size();
        // }
        // return count;
        sort(meetings.begin(),meetings.end());
        int i=0;
        int j=1;
        int busy=0;
        while(j<meetings.size()){
            vector<int>curr=meetings[i];
            vector<int>next=meetings[j];
            int cs=curr[0];
            int ce=curr[1];
            int ns=next[0];
            int ne=next[1];
            if(ce<ns){
               busy+=ce-cs+1;
               i=j;
               j++;
            }else{
                meetings[j][0]=cs;
                meetings[j][1]=max(ce,ne);
                i=j;
                j++;
            }
        }

        busy+=meetings[i][1]-meetings[i][0]+1;
        return days-busy;
    }
};