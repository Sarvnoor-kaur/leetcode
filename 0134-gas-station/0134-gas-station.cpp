class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int st=0;
        int tg=0,tc=0,tank=0;
        for(int i=0;i<gas.size();i++){
            tg+=gas[i];
            tc+=cost[i];
            tank+=gas[i]-cost[i];
            if(tank<0){
                st=i+1;
                tank=0;
            }

        }
        return tg>=tc?st:-1;
    }
};