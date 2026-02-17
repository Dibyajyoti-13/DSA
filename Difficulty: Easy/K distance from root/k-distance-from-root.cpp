/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
  public:
    // function should print the nodes at k distance from root
    vector<int> Kdistance(Node *root, int k) {
        // Your code here
        vector<int> result;
        if(root == NULL) return result;
        int distance = 0;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int levelSize = q.size();
            if(k == distance){
                for(int i = 0; i < levelSize; i++){
                    Node* node = q.front();
                    q.pop();
                    result.push_back(node->data);
                }
                return result;
            }
            
            for(int i = 0 ; i < levelSize; i++){
                Node* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            } 
            distance++;
        }
        
    }
};