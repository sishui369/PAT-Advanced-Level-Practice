#include <iostream>
#include <algorithm>
using namespace std;

// AVL树节点结构
struct Node {
    int val;        // 节点值
    int height;     // 节点高度
    Node *left, *right;
    Node(int v) : val(v), height(1), left(nullptr), right(nullptr) {}
};

// 获取节点高度
int getHeight(Node* node) {
    return node ? node->height : 0;
}

// 右旋（解决LL型不平衡）
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t = x->right;
    // 旋转
    x->right = y;
    y->left = t;
    // 更新高度
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

// 左旋（解决RR型不平衡）
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t = y->left;
    // 旋转
    y->left = x;
    x->right = t;
    // 更新高度
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

// 获取平衡因子
int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// 插入节点 + 自动平衡
Node* insert(Node* root, int val) {
    // 1. 标准BST插入
    if (!root) return new Node(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    else // 题目说数字不重复，直接返回
        return root;

    // 2. 更新高度
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // 3. 获取平衡因子，判断是否失衡
    int balance = getBalance(root);

    // 4种不平衡情况
    // LL型
    if (balance > 1 && val < root->left->val)
        return rightRotate(root);
    // RR型
    if (balance < -1 && val > root->right->val)
        return leftRotate(root);
    // LR型
    if (balance > 1 && val > root->left->val) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // RL型
    if (balance < -1 && val < root->right->val) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main() {
    int n, num;
    Node* root = nullptr;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        root = insert(root, num); 
    }
    cout << root->val << endl;
    return 0;
}