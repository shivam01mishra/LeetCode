 

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        
        // Create a result matrix with dimensions transposed
        vector<vector<char>> result(m, vector<char>(n, '.'));
        
        // Process each row in the box to simulate gravity
        for (int i = 0; i < n; i++) {
            vector<char>& v = box[i];
            int p = m - 1; // Pointer to place the stone
            for (int j = m - 1; j >= 0; j--) {
                if (v[j] == '*') { // Obstacle
                    p = j - 1; // Reset the pointer just before the obstacle
                } else if (v[j] == '#') { // Stone
                    v[j] = '.';  // Remove the stone from the current position
                    v[p--] = '#'; // Place the stone at the correct position
                }
            }
        }

        // Rotate the box 90 degrees clockwise
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[j][n - i - 1] = box[i][j];
            }
        }

        return result;
    }
};
