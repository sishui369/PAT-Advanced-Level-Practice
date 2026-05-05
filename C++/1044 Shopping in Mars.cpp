#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);  // 快读
    vector<int> a(n + 1);   // 下标从 1 开始
    
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }

    int sum = 0;            // 当前窗口和
    int min_gap = INT_MAX;  // 记录最小超出值
    vector<pair<int, int>> res; // 存答案

    // 双指针滑动窗口
    for (int l = 1, r = 0; l <= n; ++l) {
        // 扩展右指针，直到和 >= m
        while (r + 1 <= n && sum < m) {
            sum += a[++r];
        }

        // 当前窗口和 >= m
        if (sum >= m) {
            int gap = sum - m;
            // 找到更优解
            if (gap < min_gap) {
                min_gap = gap;
                res.clear();
                res.emplace_back(l, r);
            }
            // 找到相同最优解
            else if (gap == min_gap) {
                res.emplace_back(l, r);
            }
        }
        // 移动左指针，缩小窗口
        sum -= a[l];
    }

    // 输出所有答案
    for (auto& p : res) {
        printf("%d-%d\n", p.first, p.second);
    }
    
    return 0;
}