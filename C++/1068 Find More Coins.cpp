#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // 用于 memset

using namespace std;

int N, M;
vector<int> coins;
vector<int> path;
bool found = false;

// 记忆化数组：memo[i][sum] 记录在第 i 个硬币、当前金额为 sum 的状态下是否已经搜索过（且失败了）
// 因为 M <= 100，N <= 10000，这个数组大小完全在内存允许范围内
int memo[10005][105]; 

void dfs(int index, int current_sum) {
    if (found || current_sum > M) return;
    if (current_sum == M) {
        for (int i = 0; i < path.size(); i++) {
            if (i > 0) cout << " ";
            cout << path[i];
        }
        cout << endl;
        found = true;
        exit(0);
    }

    if (index >= N) return;
    
    // 【核心优化】记忆化剪枝
    // 如果这个状态之前已经来过，说明这条路走不通（否则早就 exit(0) 了），直接返回
    if (memo[index][current_sum] == 1) return;
    
    // 标记当前状态已经访问过
    memo[index][current_sum] = 1;

    // 选当前硬币
    path.push_back(coins[index]);
    dfs(index + 1, current_sum + coins[index]);
    path.pop_back();

    // 不选当前硬币
    dfs(index + 1, current_sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    if (!(cin >> N >> M)) return 0;
    coins.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());
    
    // 初始化记忆化数组为 0
    memset(memo, 0, sizeof(memo));

    dfs(0, 0);

    if (!found) {
        cout << "No Solution" << endl;
    }

    return 0;
}