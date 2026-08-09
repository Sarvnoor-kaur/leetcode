class Solution {
    public int search(int[] num, int target) {
        int l=0;
        int r=num.length-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(num[mid]<target){            
                l=mid+1;
            }else if(num[mid]>target){
                r=mid-1;
            }else{
                return mid;
            }
        }
        return -1;
    }
}