class Solution {
    public int candy(int[] rating) {
        int n=rating.length;
        int []arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=1;
        }
        for(int i=1;i<n;i++){
            if(rating[i]>rating[i-1]){
                arr[i]=arr[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(rating[i]>rating[i+1]){
                // arr[i]=arr[i+1]+1;
                arr[i]=Math.max(arr[i+1]+1,arr[i]);
            }
        }
        int um=0;
        for(int i=0;i<n;i++){
            um+=arr[i];
        }
        return um;
    }
}