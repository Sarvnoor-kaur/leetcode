class Solution {
    public int[] sortArrayByParity(int[] nums) {
        
        int [] arr=new int[nums.length];
        int [] odd=new int[nums.length];
        int k=0,j=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]%2==0){
                arr[k]=nums[i];
                k++;
            }else{
                odd[j]=nums[i];
                j++;
            }
        }
        for(int i=0;i<j;i++){
            arr[k]=odd[i];
            k++;
        }
        return arr;
    
    }
}