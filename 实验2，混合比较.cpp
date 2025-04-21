#include <iostream>
#include <string>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    string ans;          // 记录原始字符串
    long long maxVal = -1;  // 记录最大值

    // 处理十进制
    for (int i = 0; i < x; i++) {
        string s;
        cin >> s;
        long long val = stoll(s);  // 十进制直接转换
        if (val > maxVal) {
            maxVal = val;
            ans = s;
        }
    }

    // 处理八进制
    for (int i = 0; i < y; i++) {
        string s;
        cin >> s;
        long long val = stoll(s, nullptr, 8);  // 八进制转十进制
        if (val > maxVal) {
            maxVal = val;
            ans = s;
        }
    }

    // 处理十六进制
    for (int i = 0; i < z; i++) {
        string s;
        cin >> s;
        long long val = stoll(s, nullptr, 16);  // 十六进制转十进制
        if (val > maxVal) {
            maxVal = val;
            ans = s;
        }
    }

    cout << ans << endl;
    return 0;
}
