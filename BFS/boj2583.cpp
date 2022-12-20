#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int board[102][102];
int vis[102][102];

int m, n, k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m >> n >> k;

	while (k--) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		// 입력받는 좌표가 y는 행 x는 열
		// board[행][열]
		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				board[i][j] = 1;
			}
		}
	}
	// 분리된 영역 카운트
	int cnt = 0;
	// 오름차순 정렬을 위한 vector
	vector<int> ans;

	// BFS 실행
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			// 빈 공간이 아니거나 이미 방문했다면 다른곳 탐색
			if (board[i][j] == 1 || vis[i][j] == 1) {
				continue;
			}
			queue<pair<int, int>> Q;
			vis[i][j] = 1;
			Q.push({ i, j });
			// 넓이 계산을 위한 width 눈금이 1이기 때문에
			// 사각형 한개의 넓이는 1임 
			int width = 1;
			cnt++;

			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					// 방문하는곳이 board 범위 밖이라면 탈출
					if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
						continue;
					}
					// 이미 방문했거나 빈공간이 아닐경우 탈출
					if (board[nx][ny] == 1 || vis[nx][ny] == 1) {
						continue;
					}

					Q.push({ nx, ny });
					vis[nx][ny] = 1;
					width++;
				}
			}
			ans.push_back(width);
		}
	}
	// 오름차순 정렬
	sort(ans.begin(), ans.end());

	cout << cnt << "\n";
	for (auto i : ans) {
		cout << i << " ";
	}

	return 0;
}
