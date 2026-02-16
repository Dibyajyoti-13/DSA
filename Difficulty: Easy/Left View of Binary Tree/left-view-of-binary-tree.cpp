/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> result;
        if(root == nullptr) return result;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int levelSize = q.size();
            for(int i = 0; i < levelSize; i++){
                Node* temp = q.front();
                q.pop();
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                
                if(i == 0) result.push_back(temp->data);
            }
        }
        return result;
    }
};