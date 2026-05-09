class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int nlayer = min(m / 2, n / 2);

        for (int layer = 0; layer < nlayer; layer++) {

            vector<int> r, c, val;

            // left column (top to bottom-1)
            for (int i = layer; i < m - layer - 1; i++) {
                r.push_back(i);
                c.push_back(layer);
                val.push_back(grid[i][layer]);
            }

            // bottom row (left to right-1)
            for (int j = layer; j < n - layer - 1; j++) {
                r.push_back(m - layer - 1);
                c.push_back(j);
                val.push_back(grid[m - layer - 1][j]);
            }

            // right column (bottom to top+1)
            for (int i = m - layer - 1; i > layer; i--) {
                r.push_back(i);
                c.push_back(n - layer - 1);
                val.push_back(grid[i][n - layer - 1]);
            }

            // top row (right to left+1)
            for (int j = n - layer - 1; j > layer; j--) {
                r.push_back(layer);
                c.push_back(j);
                val.push_back(grid[layer][j]);
            }

            int total = val.size();
            int kk = k % total;

            vector<int> rotated(total);

        
            for (int i = 0; i < total; i++) {
                int idx = (i + total - kk) % total;
                rotated[i] = val[idx];
            }

           
            for (int i = 0; i < total; i++) {
                grid[r[i]][c[i]] = rotated[i];
            }
        }

        return grid;
    }
};