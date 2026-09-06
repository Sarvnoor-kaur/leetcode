class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int le=0;
        int r=numbers.length-1;
        while(le<r){
            if((numbers[le]+numbers[r])==target){
                return new int []{le+1,r+1};
            }else if(numbers[le]+numbers[r]<target){
                le++;
            }else{
                r--;
            }
        }
        return new int []{};
    }
}