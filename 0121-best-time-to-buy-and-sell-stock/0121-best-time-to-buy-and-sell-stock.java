class Solution {
    public int maxProfit(int[] prices) {
        
        int mini=prices[0];
        int maxi=0;
        for(int i=0;i<prices.length;i++){
            if(prices[i]<mini){
                mini=prices[i];
            }else{
                int diff=prices[i]-mini;
                maxi=Math.max(maxi,diff);
            }
        }
        return maxi;
    }
}