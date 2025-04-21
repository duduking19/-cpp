#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[10001];
int main() {
    int n;
    while(cin >> n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n,greater<int>());

    int ans = -1; 
    for (int i = 0; i <= n-2; ++i) {        
        if (a[i]< a[i+1] + a[i+2]) {
            ans = a[i] + a[i+1] + a[i+2];
            break; 
        }
    }

    cout << ans << endl;
}
    return 0;
}