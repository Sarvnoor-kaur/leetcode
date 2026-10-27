class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int [][] arr=Arrays.copyOf(intervals,intervals.length+1);
        arr[arr.length-1]=newInterval;
        Arrays.sort(arr,(a,b)->Integer.compare(a[0],b[0]));
        List<int[]>mer=new ArrayList<>();

        for(int[]inte:arr){
            if(mer.isEmpty() || mer.get(mer.size()-1)[1]<inte[0]){
                mer.add(inte);
            }else{
                mer.get(mer.size()-1)[1]=Math.max(mer.get(mer.size()-1)[1],inte[1]);
            }
        }

        return mer.toArray(new int[mer.size()-1][]);
    }
}