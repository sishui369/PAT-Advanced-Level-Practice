#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Stu {
    int id, ge, gi, sum;
    int cho[5];
} s[40005];

int quota[105];        // 学校名额
vector<int> ans[105];  // 学校录取名单
int last_school;       // 记录上一个学生录取的学校

// 排序规则：总分高 → 初试高
bool cmp(Stu a, Stu b) {
    if (a.sum != b.sum) return a.sum > b.sum;
    return a.ge > b.ge;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    for (int i = 0; i < m; i++) cin >> quota[i];
    for (int i = 0; i < n; i++) {
        cin >> s[i].ge >> s[i].gi;
        s[i].sum = s[i].ge + s[i].gi;
        s[i].id = i;
        for (int j = 0; j < k; j++) cin >> s[i].cho[j];
    }

    sort(s, s + n, cmp);

    for (int i = 0; i < n; i++) {
        // 遍历志愿
        for (int j = 0; j < k; j++) {
            int sch = s[i].cho[j];
            if (ans[sch].size() < quota[sch] || 
                (i > 0 && s[i].sum == s[i-1].sum && s[i].ge == s[i-1].ge && sch == last_school)) {
                
                ans[sch].push_back(s[i].id);
                last_school = sch; // 记录当前学生录取的学校
                break;
            }
        }
    }

    // 输出：排序+按格式打印
    for (int i = 0; i < m; i++) {
        sort(ans[i].begin(), ans[i].end());
        for (int j = 0; j < ans[i].size(); j++) {
            if (j) cout << " ";
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}