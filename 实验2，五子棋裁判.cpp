#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {0, 1, 1, 1};  // 四个方向：右，下，右下，右上
int dy[4] = {1, 0, 1, -1};

bool check(vector<string>& board, int n, char player) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != player) continue;
            // 遍历四个方向
            for (int dir = 0; dir < 4; dir++) {
                int cnt = 1;
                int x = i, y = j;
                // 往该方向数连续的player
                while (true) {
                    x += dx[dir];
                    y += dy[dir];
                    if (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == player) {
                        cnt++;
                    } else {
                        break;
                    }
                }
                if (cnt >= 5) return true; // 找到五子及以上
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> board(n);
        for (int i = 0; i < n; i++) {
            cin >> board[i];
        }

        if (check(board, n, 'B')) {
            cout << "Black" << endl;
        } else if (check(board, n, 'W')) {
            cout << "White" << endl;
        } else {
            cout << "Not so fast" << endl;
        }
    }
    return 0;
}
