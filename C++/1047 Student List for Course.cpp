#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_COURSE = 2505;
vector<string> course[MAX_COURSE];  // 存储每门课的学生
int main() {
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        string name;
        int cnt;
        cin >> name >> cnt;
        // 把学生加入对应课程
        for (int j = 0; j < cnt; ++j) {
            int c;
            cin >> c;
            course[c].push_back(name);
        }
    }
    // 按课程编号 1~K 输出
    for (int i = 1; i <= K; ++i) {
        // 排序（字典序）+ 去重
        sort(course[i].begin(), course[i].end());
        // 输出课程号 + 人数
        cout << i << " " << course[i].size() << "\n";
        // 输出学生名字
        for (const string& s : course[i]) {
            cout << s << "\n";
        }
    }
    
    return 0;
}