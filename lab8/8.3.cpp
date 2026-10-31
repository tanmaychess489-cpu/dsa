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

void inorder(node* root, vector<int>& v) {
    if (root == NULL) return;
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}

int main() {
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(8);

    int k = 2;
    vector<int> v;
    inorder(root, v);

    cout << "Kth smallest: " << v[k - 1] << endl;
    cout << "Kth largest: " << v[v.size() - k] << endl;

    return 0;
}
