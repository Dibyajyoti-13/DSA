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
    int height(TreeNode* root, int h) {
        if (root == nullptr) return h - 1;

        return max(height(root->left, h + 1), height(root->right, h + 1));
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        
        int r_height = height(root->right, 1);
        int l_height = height(root->left, 1);

        if(abs(r_height - l_height) < 2) return true;
        return false;
    }
};