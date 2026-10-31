#include <iostream>
#include <string>
#include <sstream>
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

void serializeUtil(node* root, stringstream& ss) {
    if (root == NULL) {
        ss << "#,";
        return;
    }
    ss << root->val << ",";
    serializeUtil(root->left, ss);
    serializeUtil(root->right, ss);
}

string serialize(node* root) {
    stringstream ss;
    serializeUtil(root, ss);
    string res = ss.str();
    if (!res.empty()) res.pop_back(); 
    return res;
}

node* deserializeUtil(stringstream& ss) {
    string token;
    if (!getline(ss, token, ',')) return NULL;

    if (token == "#") return NULL;

    node* root = new node(stoi(token));
    root->left = deserializeUtil(ss);
    root->right = deserializeUtil(ss);
    return root;
}

node* deserialize(string data) {
    stringstream ss(data);
    return deserializeUtil(ss);
}

void preorder(node* root) {
    if (root == NULL) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->left = new node(4);
    root->right->right = new node(5);

    string serializedData = serialize(root);
    cout << "Serialized: " << serializedData << endl;

    node* reconstructedRoot = deserialize(serializedData);

    cout << "Reconstructed Preorder: ";
    preorder(reconstructedRoot);
    cout << endl;

    return 0;
}
