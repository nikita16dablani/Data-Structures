#include <bits/stdc++.h>
using namespace std;
struct Node {
   int data;
   struct Node *left, *right;
};
void postOrderTraversal(struct Node* head) {
   struct Node* temp = head;
   unordered_set<Node*> visited;
   while (temp && visited.find(temp) == visited.end()) {
      if (temp->left &&
         visited.find(temp->left) == visited.end())
         temp = temp->left;
      else if (temp->right &&
         visited.find(temp->right) == visited.end())
         temp = temp->right;
      else {
         cout<<temp->data<<"\t";
         visited.insert(temp);
         temp = head;
      }
   }
}
struct Node* insertNode(int data){
   struct Node* node = new Node;
   node->data = data;
   node->left = NULL;
   node->right = NULL;
   return (node);
}
int main(){
   struct Node* root = insertNode(6);
   root->left = insertNode(2);
   root->right = insertNode(9);
   root->left->left = insertNode(8);
   root->left->right = insertNode(4);
   root->right->left = insertNode(7);
   root->right->left->left = insertNode(13);
   cout<<"Post Order Traversal of the binary tree :\n";
   postOrderTraversal(root);
   return 0;
}