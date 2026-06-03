#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[100005];
int num[100005];
double ans = 0;
int n;
double p, r;

void bfs() {
    queue<pair<int, double>> q;
    q.push({0, p});
    
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        int id = t.first;
        double pri = t.second;
        
        if (v[id].empty()) {
            ans += pri * num[id];
            continue;
        }
        for (int x : v[id]) {
            q.push({x, pri * (1 + r/100)});
        }
    }
}

int main() {
    cin >> n >> p >> r;
    for (int i=0; i<n; i++) {
        int k; cin >> k;
        if (k == 0) cin >> num[i];
        else {
            while(k--) {
                int x; cin >> x;
                v[i].push_back(x);
            }
        }
    }
    bfs();
    printf("%.1f", ans);
}