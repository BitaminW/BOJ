#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int n,max_cnt;
int board[101][101];
int vis[101][101];

void bfs(int x, int y, int max_hegiht) {
	queue<pair<int, int>> q;
	// 방문표시
	vis[x][y] = 1;
	q.push({x, y});

	//bfs 시작
	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			// 탐색하는곳이 보드밖이면 탐색중지
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (vis[nx][ny] == 0 && board[nx][ny] > max_hegiht) {
				vis[nx][ny] = 1; // 방문표시
				q.push({ nx,ny });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int max_height = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			
			max_height = max(max_height, board[i][j]);
		}
	}
	for (int limit = 0; limit <= max_height; limit++) {
		// 방문배열 초기화
		for (int i = 0; i < n; i++)
			fill(vis[i], vis[i] + n, 0);

		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// 탐색하는 지역이 이미 방문했거나 침수되지 않았다면
				if (board[i][j] > limit && vis[i][j] == 0) {
					bfs(i, j, limit);
					cnt++;
				}
			}
		}
		max_cnt = max(cnt, max_cnt);
	}
	cout << max_cnt;
	return 0;
}
