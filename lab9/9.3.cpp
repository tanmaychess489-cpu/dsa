#include <iostream>
#include <vector>
#include <cmath>

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

node* insert(node* root, int val) {
    if (root == NULL) return new node(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void collectClosest(node* root, double x, int k, vector<int>& res) {
    if (root == NULL) return;

    collectClosest(root->left, x, k, res);

    if (res.size() < k) {
        res.push_back(root->val);
    } else {
        double currentDiff = abs(root->val - x);
        double oldestDiff = abs(res.front() - x);

        if (currentDiff < oldestDiff || (currentDiff == oldestDiff && root->val < res.front())) {
            res.erase(res.begin());
            res.push_back(root->val);
        } else {
            return;
        }
    }

    collectClosest(root->right, x, k, res);
}

void findKClosest(node* root, int x, int k) {
    vector<int> res;
    collectClosest(root, (double)x, k, res);

    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    node* root = NULL;
    vector<int> items = {10, 5, 15, 2, 7, 12, 20, 6, 8};

    for (int val : items) {
        root = insert(root, val);
    }

    int target = 9;
    int k = 4;

    findKClosest(root, target, k);

    return 0;
}
