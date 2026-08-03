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
    vector<int> arr;
    void traverse(TreeNode* root){
        if(root == nullptr) return;

        arr.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        traverse(root);
        sort(arr.begin(), arr.end());
        int ans = INT_MAX;

        for(int i = 0; i < arr.size() - 1; i++){
            ans = min(ans, arr[i + 1] - arr[i]);
        }

        return ans;
    }
};