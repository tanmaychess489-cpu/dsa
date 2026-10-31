#include <iostream>
#include <vector>

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

node* insert(node* root, int x) {
    if (root == NULL) return new node(x);
    if (x < root->val) 
        root->left = insert(root->left, x);
    else 
        root->right = insert(root->right, x);
    return root;
}

void inorder(node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    int n, x;
    node* root = NULL;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }
    cout << "Sorted: ";
    inorder(root);
    cout << endl;
    return 0;
}
