#include <bits/stdc++.h>
using namespace std;

int board[128][128];
int color[2];

bool check(int n, int x, int y) {
    for (int i = x; i < x + n; i++)
        for (int j = y; j < y + n; j++)
            if (board[i][j] != board[x][y]) return false;   // 처음 확인했던 색과 다음칸이 다르다면 false
    
    // 위 루프에 걸리지 않았다면 같은색이고 나눠질 수 없는 최소인 경우
    return true;
}

void func(int n, int x, int y) {
    if (check(n, x, y)) {
        color[board[x][y]]++;     // count ++ 
        return;
    }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) 
            func(n / 2, x + i * n / 2, y + j * n / 2);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            cin >> board[i][j];

    func(n, 0, 0);
    cout << color[0] << "\n" << color[1];
    
    return 0;
}
