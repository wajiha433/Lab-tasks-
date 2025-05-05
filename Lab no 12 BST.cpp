#include <iostream>
using namespace std;

struct BSTNode {
    int key;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int val) {
        key = val;
        left = right = NULL;
    }
};

class BST {
public:
    BSTNode* insert(BSTNode* root, int key) {
        if (root == NULL) return new BSTNode(key);
        if (key < root->key)
            root->left = insert(root->left, key);
        else
            root->right = insert(root->right, key);
        return root;
    }

    void inorder(BSTNode* root) {
        if (root) {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }

    void preorder(BSTNode* root) {
        if (root) {
            cout << root->key << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(BSTNode* root) {
        if (root) {
            postorder(root->left);
            postorder(root->right);
            cout << root->key << " ";
        }
    }
};

int main() {
    BST bst;
    BSTNode* root = NULL;
    int keys[] = {30, 20, 40, 10, 25, 35, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++)
        root = bst.insert(root, keys[i]);

    cout << "--- BST Traversals ---\n";
    cout << "Inorder: "; bst.inorder(root); cout << "\n";
    cout << "Preorder: "; bst.preorder(root); cout << "\n";
    cout << "Postorder: "; bst.postorder(root); cout << "\n";

    return 0;
}
