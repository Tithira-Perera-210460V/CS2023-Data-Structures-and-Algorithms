#include <iostream>
using namespace std;

struct node {
  int key;
  node *left, *right, *parent;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root == NULL)
    return;
  
  traverseInOrder(root->left);
  cout << root->key << " ";
  traverseInOrder(root->right);
}

// Insert a node
struct node* insertNode(struct node* root, int key) {
    if (root == NULL) {
        node* newNode = new node;
        newNode->key = key;

        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else if (key <= root->key) {
        root->left = insertNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = insertNode(root->right, key);
    }
    return root;
}

node* inorderSuccessor(node* node) {
    if (node->right != NULL) {
        node = node->right;
        while (node->left != NULL){
            node = node->left;
        }
        return node;
    }

    while (node->parent != NULL && node != node->parent->left) {
        node = node->parent;
    }

    return node->parent;
}

//deleting a node
node* deleteNode(node* root, int data){
    if (root == NULL)
        return root;

    else if (data <= root->key)
        root->left = deleteNode(root->left, data);
    
    else if (data > root->key)
        root->right = deleteNode(root->right, data);
    
    else{
        if (root-> left == NULL && root->right == NULL){
            root = NULL;
            delete root;
        }

        else if (root->left == NULL){
            node* tempNode = root;
            root = root->right;
            tempNode = NULL;
            delete tempNode;
        }

        else if (root->right == NULL){
            node* tempNode = root;
            root = root->left;
            tempNode = NULL;
            delete tempNode;
        }

        else{
            node* tempNode = inorderSuccessor(root);
            root->key = tempNode->key;
            root->right = deleteNode(root->right, tempNode->key);
        }
    }

    return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}
