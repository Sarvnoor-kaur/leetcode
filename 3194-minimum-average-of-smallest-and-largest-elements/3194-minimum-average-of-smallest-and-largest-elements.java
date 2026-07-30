class Solution {
    public double minimumAverage(int[] nums) {
        Arrays.sort(nums);
        int i=0,e=nums.length-1;
        ArrayList<Double>arr=new ArrayList<>();
        while(i<e){
            int um=nums[i]+nums[e];
            double avg=um/2.0;
            arr.add(avg);
            i++;
            e--;
        }

        double mini=Collections.min(arr);
        return mini;

    }
}