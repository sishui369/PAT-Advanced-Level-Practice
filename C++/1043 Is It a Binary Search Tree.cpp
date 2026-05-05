#include <iostream>
#include <vector>
using namespace std;

vector<int> pre, post;

// 检查是否是 BST 的前序，并生成后序
bool checkBST(int l, int r) {
    if (l > r) return true;
    int root = pre[l];
    int i = l + 1;
    // 左子树：都 < root
    while (i <= r && pre[i] < root) i++;
    int mid = i;
    // 右子树必须都 >= root
    while (i <= r && pre[i] >= root) i++;
    if (i <= r) return false; // 不满足BST规则
    
    if (checkBST(l + 1, mid - 1) && checkBST(mid, r)) {
        post.push_back(root);
        return true;
    }
    return false;
}

// 检查是否是 镜像BST 的前序，并生成后序
bool checkMirror(int l, int r) {
    if (l > r) return true;
    int root = pre[l];
    int i = l + 1;
    // 镜像右子树：都 >= root
    while (i <= r && pre[i] >= root) i++;
    int mid = i;
    // 镜像左子树必须都 < root
    while (i <= r && pre[i] < root) i++;
    if (i <= r) return false; // 不满足镜像规则
    
    if (checkMirror(l + 1, mid - 1) && checkMirror(mid, r)) {
        post.push_back(root);
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    pre.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }

    // 先检查普通BST
    if (checkBST(0, n - 1)) {
        cout << "YES\n";
        for (int i = 0; i < post.size(); i++) {
            if (i > 0) cout << " ";
            cout << post[i];
        }
        cout << endl;
    } 
    // 再检查镜像BST
    else {
        post.clear();
        if (checkMirror(0, n - 1)) {
            cout << "YES\n";
            for (int i = 0; i < post.size(); i++) {
                if (i > 0) cout << " ";
                cout << post[i];
            }
            cout << endl;
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}