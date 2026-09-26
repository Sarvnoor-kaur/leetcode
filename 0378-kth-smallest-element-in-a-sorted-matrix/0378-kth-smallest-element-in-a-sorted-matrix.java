// class Solution {
//     public int kthSmallest(int[][] matrix, int k) {

//         int m = matrix.length;

//         // Store all elements
//         ArrayList<Integer> flat = new ArrayList<>();

//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < m; j++) {
//                 flat.add(matrix[i][j]);
//             }
//         }

//         // Sort
//         Collections.sort(flat);

//         // kth smallest = index k-1
//         return flat.get(k - 1);
//     }
// }





class Solution {
    public int kthSmallest(int[][] matrix, int k) {

        PriorityQueue<Integer> pq =
            new PriorityQueue<>(Collections.reverseOrder());

        for (int[] row : matrix) {
            for (int num : row) {

                pq.add(num);

                if (pq.size() > k) {
                    pq.poll();
                }
            }
        }

        return pq.peek();
    }
}