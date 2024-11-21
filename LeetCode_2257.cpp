class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // Initialize the grid
        vector<vector<char>> grid(m, vector<char>(n, '\0'));

        // Mark guards on the grid
        for (auto& guard : guards) {
            int x = guard[0], y = guard[1];
            grid[x][y] = 'G';
        }

        // Mark walls on the grid
        for (auto& wall : walls) {
            int x = wall[0], y = wall[1];
            grid[x][y] = 'W';
        }

        // Mark cells guarded by each guard
        for (auto& guard : guards) {
            int x = guard[0], y = guard[1];

            // Right direction
            for (int j = y + 1; j < n; ++j) {
                if (grid[x][j] == 'W' || grid[x][j] == 'G') break;
                grid[x][j] = 'C';
            }

            // Left direction
            for (int j = y - 1; j >= 0; --j) {
                if (grid[x][j] == 'W' || grid[x][j] == 'G') break;
                grid[x][j] = 'C';
            }

            // Down direction
            for (int i = x + 1; i < m; ++i) {
                if (grid[i][y] == 'W' || grid[i][y] == 'G') break;
                grid[i][y] = 'C';
            }

            // Up direction
            for (int i = x - 1; i >= 0; --i) {
                if (grid[i][y] == 'W' || grid[i][y] == 'G') break;
                grid[i][y] = 'C';
            }
        }

        // Count unguarded cells
        int unguarded = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '\0') { // Unoccupied and unguarded
                    ++unguarded;
                }
            }
        }

        return unguarded;
    }
};
