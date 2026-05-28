#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 10005;
const int MAXK = 10;

struct User {
    int id;
    int score[MAXK];
    int total;
    int perfect;
    bool show;
} u[MAXN];

int p[MAXK];
int n, k, m;

bool cmp(User a, User b) {
    if (a.total != b.total) return a.total > b.total;
    if (a.perfect != b.perfect) return a.perfect > b.perfect;
    return a.id < b.id;
}

int main() {
    cin >> n >> k >> m;
    for (int i = 1; i <= k; i++) cin >> p[i];

    for (int i = 1; i <= n; i++) {
        u[i].id = i;
        u[i].total = 0;
        u[i].perfect = 0;
        u[i].show = false;
        memset(u[i].score, -1, sizeof(u[i].score));
    }

    while (m--) {
        int id, pid, sco;
        cin >> id >> pid >> sco;

        if (sco == -1) {
            if (u[id].score[pid] == -1) u[id].score[pid] = 0;
            continue;
        }

        u[id].show = true;
        if (sco > u[id].score[pid]) {
            if (u[id].score[pid] != -1) u[id].total -= u[id].score[pid];
            u[id].score[pid] = sco;
            u[id].total += sco;
            if (sco == p[pid]) u[id].perfect++;
        }
    }

    sort(u + 1, u + n + 1, cmp);

    int rank = 1;
    for (int i = 1; i <= n; i++) {
        if (!u[i].show) continue;
        if (i > 1 && u[i].total != u[i - 1].total) rank = i;

        printf("%d %05d %d", rank, u[i].id, u[i].total);
        for (int j = 1; j <= k; j++) {
            if (u[i].score[j] == -1) printf(" -");
            else printf(" %d", u[i].score[j]);
        }
        printf("\n");
    }
    return 0;
}