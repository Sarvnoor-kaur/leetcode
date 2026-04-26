class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int profit;
        // int profitmax=0;
        // int max=INT_MIN;
        // int min=INT_MAX;
        // for(int i=0;i<prices.size();i++){
        //     if(prices[i]<min){
        //         min=prices[i];
        //         for(int j=i;j<prices.size();j++){
        //            if(prices[i]>max){
        //             max=prices[i];
        //            } 
        //         }
        //     }
        //     profit=max-min;
        //     if(profit>profitmax){
        //         profitmax=profit;
        //     }


        // }
        // return profitmax;

        int profit=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]){
                profit+=(prices[i]-prices[i-1]);
            }
        }
        return profit;
        
    }
};