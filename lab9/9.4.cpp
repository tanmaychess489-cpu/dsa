#include <iostream>
#include <algorithm>
#include <climits>

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

struct SubtreeInfo {
    bool isBST;
    int minVal;
    int maxVal;
    int sum;
};

SubtreeInfo findMaxBSTSumUtil(node* root, int& maxBSTSum) {
    if (root == NULL) {
        return {true, INT_MAX, INT_MIN, 0};
    }

    SubtreeInfo leftInfo = findMaxBSTSumUtil(root->left, maxBSTSum);
    SubtreeInfo rightInfo = findMaxBSTSumUtil(root->right, maxBSTSum);

    SubtreeInfo currentInfo;

    if (leftInfo.isBST && rightInfo.isBST && root->val > leftInfo.maxVal && root->val < rightInfo.minVal) {
        currentInfo.isBST = true;
        currentInfo.minVal = min(root->val, leftInfo.minVal);
        currentInfo.maxVal = max(root->val, rightInfo.maxVal);
        currentInfo.sum = root->val + leftInfo.sum + rightInfo.sum;
        
        maxBSTSum = max(maxBSTSum, currentInfo.sum);
    } else {
        currentInfo.isBST = false;
        currentInfo.minVal = 0;
        currentInfo.maxVal = 0;
        currentInfo.sum = 0;
    }

    return currentInfo;
}

int maxBSTSum(node* root) {
    int maxBSTSum = INT_MIN;
    findMaxBSTSumUtil(root, maxBSTSum);
    return maxBSTSum == INT_MIN ? 0 : maxBSTSum;
}

int main() {
    node* root = new node(5);
    root->left = new node(4);
    root->right = new node(8);
    root->left->left = new node(3);
    root->left->right = new node(6);
    root->right->left = new node(7);
    root->right->right = new node(9);

    cout << "Maximum BST subtree sum = " << maxBSTSum(root) << endl;

    return 0;
}
