#include <iostream>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;
    node(int x) {
        val = x;
        left = right = NULL;
    }
};

bool mirror(node* a, node* b) {
    if (a == NULL && b == NULL) return true;
    if (a == NULL || b == NULL) return false;
    return a->val == b->val && mirror(a->left, b->right) && mirror(a->right, b->left);
}

bool isSymmetric(node* root) {
    if (root == NULL) return true;
    return mirror(root->left, root->right);
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(4);
    root->right->right = new node(3);

    if (isSymmetric(root))
        cout << "Symmetric" << endl;
    else
        cout << "Not symmetric" << endl;

    return 0;
}
