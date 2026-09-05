class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {

        // Adjacency list
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

        for (int i = 0; i < numCourses; i++) {
            adj.add(new ArrayList<>());
        }

        // Indegree array
        int[] indeg = new int[numCourses];

        // Build graph
        for (int[] p : prerequisites) {

            int e = p[0];
            int f = p[1];

            adj.get(f).add(e);
            indeg[e]++;
        }

        // Queue
        Queue<Integer> q = new LinkedList<>();

        // Add courses with indegree 0
        for (int i = 0; i < numCourses; i++) {

            if (indeg[i] == 0) {
                q.add(i);
            }
        }

        // Answer
        ArrayList<Integer> an = new ArrayList<>();

        // BFS
        while (!q.isEmpty()) {

            int v = q.poll();

            an.add(v);

            for (int ne : adj.get(v)) {

                indeg[ne]--;

                if (indeg[ne] == 0) {
                    q.add(ne);
                }
            }
        }

        // Cycle detected
        if (an.size() != numCourses) {
            return new int[]{};
        }

        // Convert ArrayList<Integer> to int[]
        int[] result = new int[an.size()];

        for (int i = 0; i < an.size(); i++) {
            result[i] = an.get(i);
        }

        return result;
    }
}