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
    void inorder(TreeNode* root, vector<int> &result){
        if(root == nullptr) return;

        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result;
        vector<int> v1;
        vector<int> v2;

        inorder(root1, v1);
        inorder(root2, v2);

        int i = 0, j = 0;
        while(i < v1.size() && j < v2.size()){
            if(v1[i] < v2[j]) result.push_back(v1[i++]);
            else result.push_back(v2[j++]);
        }

        while(i < v1.size()) result.push_back(v1[i++]);

        while(j < v2.size()) result.push_back(v2[j++]);

        return result;
    }
};