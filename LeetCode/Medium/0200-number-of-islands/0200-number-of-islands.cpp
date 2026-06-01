class Solution {
public:
    int m, n;

    void dfs(int row, int col, vector<vector<char>>& grid){
        if(row < 0 || col < 0 || row >= m || col >= n || grid[row][col] != '1') return;
        grid[row][col] = '-';

        dfs(row - 1, col, grid); // up
        dfs(row + 1, col, grid); // down
        dfs(row, col - 1, grid); // left
        dfs(row, col + 1, grid); // right
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
};