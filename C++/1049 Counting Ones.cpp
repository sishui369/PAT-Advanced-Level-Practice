#include<iostream>
using namespace std;
int countone(int n){

}
int main(){
    int n,i,j,k;
    cin>>n;
    int count = 0;  // 统计1的总个数
    int base = 1;   // 位权：个位1，十位10，百位100...
    int high, cur, low; // 高位、当前位、低位

    while (base <= n) {
        high = n / (base * 10);  // 高位数字
        cur = (n / base) % 10;   // 当前位数字
        low = n % base;         // 低位数字

        // 分三种情况计算当前位1出现的次数
        if (cur < 1) {
            count += high * base;
        } else if (cur == 1) {
            count += high * base + low + 1;
        } else {
            count += (high + 1) * base;
        }

        base *= 10; // 处理下一位
    }

    cout << count << endl;
    return 0;
}