class Solution {
public:
    vector<int> boundaryTraversal(vector<vector<int>>& mat) {
        vector<int> ans;
        int r = mat.size(), c = mat[0].size();

        // top row
        for (int j = 0; j < c; j++)
            ans.push_back(mat[0][j]);

        // right column (excluding top)
        for (int i = 1; i < r; i++)
            ans.push_back(mat[i][c - 1]);

        // bottom row (excluding corners)
        if (r > 1) {
            for (int j = c - 2; j >= 0; j--)
                ans.push_back(mat[r - 1][j]);
        }

        // left column (excluding corners)
        if (c > 1) {
            for (int i = r - 2; i > 0; i--)
                ans.push_back(mat[i][0]);
        }

        return ans;
    }
};
