#include <iostream>
#include <queue>

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

int minDepth(node* root) {
    if (root == NULL) return 0;
    queue<pair<node*, int> > q;
    q.push(make_pair(root, 1));
    
    while (!q.empty()) {
        node* t = q.front().first;
        int d = q.front().second;
        q.pop();
        
        if (t->left == NULL && t->right == NULL) return d;
        if (t->left) q.push(make_pair(t->left, d + 1));
        if (t->right) q.push(make_pair(t->right, d + 1));
    }
    return 0;
}

int main() {
    node* root = new node(3);
    root->left = new node(9);
    root->right = new node(20);
    root->right->left = new node(15);
    root->right->right = new node(7);

    cout << "Minimum depth: " << minDepth(root) << endl;
    return 0;
}
