#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1020;
const int INF = INT_MAX / 2;

int N, M, K, Ds;
vector<pair<int, int>> g[MAX];
int d[MAX];
bool vis[MAX];

// 字符串转编号
int id(string s) {
    if (s[0] == 'G') {
        int n = s[1] - '0';
        return 1000 + n;
    }
    int num = 0;
    for (char c : s) num = num * 10 + c - '0';
    return num;
}

// Dijkstra 最短路
void dijk(int st) {
    fill(d, d + MAX, INF);
    memset(vis, 0, sizeof(vis));
    d[st] = 0;

    for (int i = 0; i < N+M; i++) {
        int u = -1, mn = INF;
        for (int j = 1; j < MAX; j++)
            if (!vis[j] && d[j] < mn) mn = d[j], u = j;

        if (u == -1) break;
        vis[u] = 1;

        for (auto e : g[u]) {
            int v = e.first, w = e.second;
            if (d[v] > d[u] + w)
                d[v] = d[u] + w;
        }
    }
}

int main() {
    cin >> N >> M >> K >> Ds;

    for (int i = 0; i < K; i++) {
        string a, b;
        int len;
        cin >> a >> b >> len;
        int u = id(a), v = id(b);
        g[u].push_back({v, len});
        g[v].push_back({u, len});
    }

    int best = -1;
    double bestMin = -1, bestAvg = INF;

    // 遍历每个加油站 G1~GM
    for (int i = 1; i <= M; i++) {
        dijk(1000 + i);

        bool ok = 1;
        double sum = 0, minD = INF;

        for (int j = 1; j <= N; j++) {
            if (d[j] > Ds) { ok = 0; break; }
            sum += d[j];
            if (d[j] < minD) minD = d[j];
        }

        if (!ok) continue;
        double avg = sum / N;

        if (minD > bestMin || 
           (minD == bestMin && avg < bestAvg) || 
           (minD == bestMin && avg == bestAvg && i < best)) {
            best = i;
            bestMin = minD;
            bestAvg = avg;
        }
    }

    if (best == -1) cout << "No Solution";
    else printf("G%d\n%.1f %.1f", best, bestMin, bestAvg);

    return 0;
}