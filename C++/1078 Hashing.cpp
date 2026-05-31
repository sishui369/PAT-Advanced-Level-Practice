#include <iostream>
#include <cstring>
using namespace std;

int ht[10010];

// 质数判断
bool isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int main() {
    int m, n, x;
    cin >> m >> n;

    // 找最小质数表长
    while (!isPrime(m)) m++;

    memset(ht, -1, sizeof ht);

    for (int i = 0; i < n; i++) {
        cin >> x;
        int p = -1;

        // 二次探测
        for (int j = 0; j < m; j++) {
            int pos = (x % m + j*j) % m;
            if (ht[pos] == -1) {
                ht[pos] = x;
                p = pos;
                break;
            }
        }

        if (i) cout << " ";
        p == -1 ? cout << "-" : cout << p;
    }
    return 0;
}