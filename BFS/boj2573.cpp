#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int board[301][301];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int row, col;

	cin >> row >> col;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> board[i][j];
		}
	}



	return 0;
}

