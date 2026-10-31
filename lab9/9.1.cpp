#include <iostream>
#include <map>
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

void topView(node* root) {
    if (root == NULL) return;
    
    map<int, int> topNodeMap;
    queue<pair<node*, int>> q;
    
    q.push(make_pair(root, 0));
    
    while (!q.empty()) {
        node* curr = q.front().first;
        int hd = q.front().second;
        q.pop();
        
        if (topNodeMap.find(hd) == topNodeMap.end()) {
            topNodeMap[hd] = curr->val;
        }
        
        if (curr->left) q.push(make_pair(curr->left, hd - 1));
        if (curr->right) q.push(make_pair(curr->right, hd + 1));
    }
    
    for (auto it : topNodeMap) {
        cout << it.second << " ";
    }
    cout << endl;
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(4);
    root->left->right->right = new node(5);
    root->left->right->right->right = new node(6);
    
    topView(root);
    
    return 0;
}
