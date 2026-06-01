class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(),cost.rend());
        int amount=0;
        int count=0;
        for(int i=0;i<cost.size();i++){
            count++;
            amount+=cost[i];
            if(count==2){
                count=0;
                i++;
            }
            

        }
        return amount;
    }
};