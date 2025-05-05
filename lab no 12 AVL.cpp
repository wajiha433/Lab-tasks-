#include <iostream>
#include <algorithm> // For max()
using namespace std;

struct AVLNode {
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(int val) {
        key = val;
        left = right = NULL;
        height = 1;
    }
};

class AVL {
private:
    int height(AVLNode* node) {
        return node ? node->height : 0;
    }

    int getBalance(AVLNode* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

public:
    AVLNode* insert(AVLNode* root, int key) {
        if (root == NULL) return new AVLNode(key);

        if (key < root->key)
            root->left = insert(root->left, key);
        else if (key > root->key)
            root->right = insert(root->right, key);
        else
            return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);

        // Left Left
        if (balance > 1 && key < root->left->key)
            return rotateRight(root);

        // Right Right
        if (balance < -1 && key > root->right->key)
            return rotateLeft(root);

        // Left Right
        if (balance > 1 && key > root->left->key) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        // Right Left
        if (balance < -1 && key < root->right->key) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    void inorder(AVLNode* root) {
        if (root) {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }

    void preorder(AVLNode* root) {
        if (root) {
            cout << root->key << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(AVLNode* root) {
        if (root) {
            postorder(root->left);
            postorder(root->right);
            cout << root->key << " ";
        }
    }
};

int main() {
    AVL avl;
    AVLNode* root = NULL;
    int keys[] = {30, 20, 40, 10, 25, 35, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++)
        root = avl.insert(root, keys[i]);

    cout << "--- AVL Traversals ---\n";
    cout << "Inorder: "; avl.inorder(root); cout << "\n";
    cout << "Preorder: "; avl.preorder(root); cout << "\n";
    cout << "Postorder: "; avl.postorder(root); cout << "\n";

    return 0;
}
