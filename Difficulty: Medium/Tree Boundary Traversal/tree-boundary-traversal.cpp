/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void leftBoundary(Node* root, vector<int>& result){
        if(root == NULL || (!root->left && !root->right)) return;  
        
        result.push_back(root->data);
        
        if(root->left) leftBoundary(root->left, result);
        else leftBoundary(root->right, result);
    }
    
    void rightBoundary(Node* root, vector<int>& result){
        if(root == NULL || (!root->left && !root->right)) return;  
        
        if(root->right) rightBoundary(root->right, result);
        else rightBoundary(root->left, result);
        
        result.push_back(root->data);
    }
    
    void dfs(Node* root, vector<int>& result){
        if(root == NULL) return;
        
        if(!root->left && !root->right) {result.push_back(root->data); return;}
        
        dfs(root->left, result);
        dfs(root->right, result);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(root == NULL) return ans;
        
        ans.push_back(root->data);
        
        leftBoundary(root->left, ans);
        dfs(root->left, ans);
        dfs(root->right, ans);
        rightBoundary(root->right, ans);
        
        return ans;
    }
};