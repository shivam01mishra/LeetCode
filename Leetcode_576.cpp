class Solution {
public:
 int r[4] = {1, -1, 0, 0};
int c[4] = {0, 0, 1, -1};
int mod=1e9+7;

int dp[51][51][51];

int dfs(int row, int col, int move, int m, int n) {
    // Base case: no moves left
    if (move == 0) 
        return 0;  // Assuming you want to count the number of valid paths
    if(dp[row][col][move]!=-1)
    return dp[row][col][move];
    int count = 0;

    for (int i = 0; i < 4; i++) {
        int n_r = row + r[i];
        int n_c = col + c[i];

        // Check if the next move is within bounds
        if (n_r >= 0 && n_r < m && n_c >= 0 && n_c < n) {
            count =(count+ dfs(n_r, n_c, move - 1, m, n))%mod;
            
        }
        else
        count++;
    }

    return dp[row][col][move]=count;
}
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return dfs(startRow,startColumn,maxMove,m,n);
        
    }
};
