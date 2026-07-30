class Solution {
public:
    int findMaxValue(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<vector<int>> suffixMax(n, vector<int>(n));

        suffixMax[n-1][n-1] = mat[n-1][n-1];

        for (int j = n - 2; j >= 0; j--) {
            suffixMax[n-1][j] = max(mat[n-1][j], suffixMax[n-1][j + 1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i][n-1] = max(mat[i][n-1], suffixMax[i + 1][n-1]);
        }

        int ans = INT_MIN;

        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {

                ans = max(ans, suffixMax[i + 1][j + 1] - mat[i][j]);

                suffixMax[i][j] = max({
                    mat[i][j],
                    suffixMax[i + 1][j],
                    suffixMax[i][j + 1],
                    suffixMax[i + 1][j + 1]
                });
            }
        }

        return ans;
    }
};