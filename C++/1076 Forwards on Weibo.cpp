#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 1005;
vector<int> adj[MAX];
int N, L;
int bfs(int start) {
    bool vis[MAX] = {false};
    queue<pair<int, int>> q;
    q.push({start, 0});
    vis[start] = true;
    int cnt = 0;

    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        int u = now.first;
        int level = now.second;

        if (level >= L) continue;

        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                cnt++;
                q.push({v, level + 1});
            }
        }
    }
    return cnt;
}
int main() {
    cin >> N >> L;
    for (int i = 1; i <= N; i++) {
        int M;
        cin >> M;
        while (M--) {
            int x;
            cin >> x;
            adj[x].push_back(i);  // 关键：x被i关注 → x发博，i能看到
        }
    }
    int K;
    cin >> K;
    while (K--) {
        int id;
        cin >> id;
        cout << bfs(id) << endl;
    }
    return 0;
}