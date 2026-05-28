#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100005;
int val[MAX], next_[MAX];  // 改这里！data → val
int list[MAX];
int len;
int main() {
    int head, n, k;
    cin >> head >> n >> k;
    for (int i = 0; i < n; i++) {
        int addr, d, ne;
        cin >> addr >> d >> ne;
        val[addr] = d;        // 改这里
        next_[addr] = ne;
    }
    int p = head;
    while (p != -1) {
        list[len++] = p;
        p = next_[p];
    }
    for (int i = 0; i + k <= len; i += k) {
        reverse(list + i, list + i + k);
    }
    for (int i = 0; i < len; i++) {
        int cur = list[i];
        if (i != len - 1)
            printf("%05d %d %05d\n", cur, val[cur], list[i+1]); // 改这里
        else
            printf("%05d %d -1\n", cur, val[cur]);               // 改这里
    }
    return 0;
}