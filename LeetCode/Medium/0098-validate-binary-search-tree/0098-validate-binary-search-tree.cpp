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
    bool check(TreeNode* root, int min, int max){
        if(root == nullptr) return true;

        if(root->val >= min && root->val <= max) return check(root->left, min, root->val) && check(root->right, root->val, max);
        else return false;
    }

    bool isValidBST(TreeNode* root) {
        long min = INT_MIN;
        long max = INT_MAX;
        return check(root, min, max); 
    }
};