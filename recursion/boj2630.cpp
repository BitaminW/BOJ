#include <bits/stdc++.h>

using namespace std;

int n;
int color[2]; // 0 하양 1파랑
int board[130][130];

// index
// n / 2 - 1 ,  n - 1
void sol(int y, int x, int n) {
	
	bool cur_color = board[y][x];  // 현재 색
	bool check = true;			   // 종이 분할 여부

	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (cur_color != board[i][j]) {
				check = false;
				break;
			}
		}
	}

	// 나눠지지 않는다면
	if (check) {
		// 색 카운트
		color[cur_color]++;
	}
	else {
		sol(y, x, n / 2);
		sol(y + (n / 2), x, n / 2);
		sol(y, x + (n / 2), n / 2);
		sol(y + (n / 2), x + (n / 2), n / 2);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	sol(0, 0, n);
	cout << color[0] << "\n" << color[1];

	return 0;
}
