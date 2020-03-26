#include <iostream>
#include <fstream>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/


  void leftTree(Node* root) {
    if (root != nullptr) {
      if (root->left != nullptr) {
        leftTree(root->left);
      }
      cout << root->data << " ";
    }
  }

  void rightTree(Node* root) {
    if (root != nullptr) {
      cout << root->data << " ";
    }
    if (root->right != nullptr) {
      rightTree(root->right);
    }
  }

  void topView(Node * root) {
    // Left tree bottom up to Root
    leftTree(root);

    // Right subtree from Root to bottom
    rightTree(root->right);



  }


}; //End of Solution

int main() {
  ofstream fout("output.txt");
  ifstream fin("input.txt");

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    fin >> t;

    while(t-- > 0) {
        fin >> data;
        root = myTree.insert(root, data);
    }

	myTree.topView(root);
    return 0;
}
