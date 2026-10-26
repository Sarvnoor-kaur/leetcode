class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals,(a,b)->Integer.compare(a[0],b[0]));

        List<int[]>mer=new ArrayList<>();

        for(int [] inte:intervals){
            if(mer.isEmpty()||mer.get(mer.size()-1)[1]<inte[0]){
                mer.add(inte);
            }else{
                mer.get(mer.size()-1)[1]=Math.max(mer.get(mer.size()-1)[1],inte[1]);
            }
        }
        return mer.toArray(new int[mer.size()][]);
    }
}