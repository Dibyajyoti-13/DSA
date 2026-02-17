/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  Node* minimum(Node* root){
      if(root->left == nullptr) return root;
      return minimum(root->left);
  }
    int minValue(Node* root) {
        // code here
        Node* r = minimum(root);
        return r->data;
    }
};