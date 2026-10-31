#include <iostream>
#include <algorithm>

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

void correctBSTUtil(node* root, node*& first, node*& middle, node*& last, node*& prev) {
    if (root == NULL) return;

    correctBSTUtil(root->left, first, middle, last, prev);

    if (prev && root->val < prev->val) {
        if (!first) {
            first = prev;
            middle = root;
        } else {
            last = root;
        }
    }

    prev = root;

    correctBSTUtil(root->right, first, middle, last, prev);
}

void recoverTree(node* root) {
    node *first = NULL, *middle = NULL, *last = NULL, *prev = NULL;

    correctBSTUtil(root, first, middle, last, prev);

    if (first && last) {
        swap(first->val, last->val);
    } else if (first && middle) {
        swap(first->val, middle->val);
    }
}

void inorder(node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    node* root = new node(6);
    root->left = new node(3);
    root->right = new node(8);
    root->left->left = new node(1);
    root->left->right = new node(7);
    root->right->left = new node(4);
    root->right->right = new node(9);

    recoverTree(root);

    inorder(root);
    cout << endl;

    return 0;
}
