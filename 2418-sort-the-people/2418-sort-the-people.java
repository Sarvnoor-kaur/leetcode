import java.util.*;

class Solution {
    public String[] sortPeople(String[] names, int[] heights) {

        PriorityQueue<int[]>pq = new PriorityQueue<>(
            (a, b)->b[0] - a[0]
        );

        for (int i = 0; i < names.length; i++) {
            pq.add(new int[]{heights[i], i});
        }

        String[] ans = new String[names.length];

        int i = 0;

        while (!pq.isEmpty()) {
            int[] person = pq.poll();

            ans[i] = names[person[1]];
            i++;
        }

        return ans;
    }
}