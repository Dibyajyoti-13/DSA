/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int, vector<pair<int,int>>> mp;

    void dfs(TreeNode* root, int col, int row){
        if(!root) return;

        mp[col].push_back({row, root->val});
        dfs(root->left, col-1, row+1);
        dfs(root->right, col+1, row+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);

        vector<vector<int>> ans;
        for(auto &p : mp){
            auto &v = p.second;
            sort(v.begin(), v.end());
            vector<int> col;
            for(auto &x : v) col.push_back(x.second);
            ans.push_back(col);
        }
        return ans;
    }
};
