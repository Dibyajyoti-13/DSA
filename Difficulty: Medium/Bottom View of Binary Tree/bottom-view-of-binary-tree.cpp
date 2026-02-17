/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> result;
        if(!root) return result;
        
        queue<pair<Node*, int>> q;
        map<int, int> view;
        
        q.push({root, 0});
        
        while(!q.empty()){
            int levelSize = q.size();
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            int d = it.second;
            view[d] = node->data;
            
            if(node->left) q.push({node->left, d - 1});
            if(node->right) q.push({node->right, d + 1});
        }
        
        for(auto it : view){
            result.push_back(it.second);
        }
        return result;
    }
};