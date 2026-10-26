class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer>st=new HashSet<>();
        Set<Integer>re=new HashSet<>();

        for(int a:nums1){
            st.add(a);
        }
        for(int b:nums2){
            if(st.contains(b)){
                re.add(b);
            }
        }
        int i=0;
        int [] arr=new int[re.size()];
        for(int a:re){
            arr[i]=a;
            i++;
        }
        return arr;
    }
}