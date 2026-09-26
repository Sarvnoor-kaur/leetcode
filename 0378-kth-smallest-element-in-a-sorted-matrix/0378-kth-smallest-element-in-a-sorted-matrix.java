class Solution {
    public int kthSmallest(int[][] matrix, int k) {

        int m = matrix.length;

        // Store all elements
        ArrayList<Integer> flat = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                flat.add(matrix[i][j]);
            }
        }

        // Sort
        Collections.sort(flat);

        // kth smallest = index k-1
        return flat.get(k - 1);
    }
}