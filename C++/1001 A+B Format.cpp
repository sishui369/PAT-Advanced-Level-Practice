#include <iostream>
#include <string>
#include <algorithm>  // reverse 函数
using namespace std;
int main() {
    long long a, b;  // 防止溢出，用 long long
    cin >> a >> b;
    long long sum = a + b;
    if (sum == 0) {
        cout << "0" << endl;
        return 0;
    }
    bool isNegative = false;
    if (sum < 0) {
        isNegative = true;
        sum = -sum;
    }

    string res;
    int cnt = 0;
    while (sum > 0) {
        if (cnt == 3) {
            res += ',';
            cnt = 0;
        }
        res += (sum % 10) + '0';
        sum /= 10;
        cnt++;
    }
    if (isNegative) {
        res += '-';
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}
