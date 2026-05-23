#include <iostream>
using namespace std;
const int M = 100005;
int a[M];
bool vis[M] = {false};
int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (vis[i] || a[i] == i) continue;
        int cnt = 0, cur = i;
        while (!vis[cur]) {
            vis[cur] = true;
            cur = a[cur];
            cnt++;
        }
        if (i == 0) ans += cnt - 1;
        else ans += cnt + 1;
    }
    cout << ans;
    return 0;
}