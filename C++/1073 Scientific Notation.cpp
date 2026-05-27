#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    // 输出符号
    if (s[0] == '-') cout << "-";
    // 找到 E 的位置
    int e = 0;
    while (s[e] != 'E') e++;
    // 数字部分：去掉小数点
    string num = "";
    for (int i = 1; i < e; i++) {
        if (s[i] != '.') num += s[i];
    }
    // 指数部分（转成数字）
    int exp = 0;
    for (int i = e + 2; i < s.size(); i++) {
        exp = exp * 10 + (s[i] - '0');
    }
    // 开始输出
    if (s[e + 1] == '-') { // 指数负号
        cout << "0.";
        // 输出 exp-1 个 0
        for (int i = 1; i < exp; i++) cout << "0";
        cout << num;
    } else { // 指数正号
        cout << num[0]; // 先输出第一位
        int cnt = 0;
        // 输出后面的数字，到了exp位置加小数点
        for (int i = 1; i < num.size(); i++) {
            cout << num[i];
            cnt++;
            if (cnt == exp && i != num.size() - 1) cout << ".";
        }
        // 不够补0
        while (cnt < exp) {
            cout << "0";
            cnt++;
        }
    }
    return 0;
}