#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int board[1002][1002];
int visF[1002][1002];
int visS[1002][1002];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int t, w, h;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	for (int ti = 0; ti < t; ti++) {
		bool escape = false;
		queue<pair <int, int>> Qf = {}, Qs = {};
		cin >> w >> h;
		// 불과 타겟판 0으로 초기화
		for (int i = 0; i < h; i++) {
			fill(visF[i], visF[i] + w, 0);
			fill(visS[i], visS[i] + w, 0);
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				char c;
				cin >> c;
				//벽이면 보드 -1로 초기화
				if (c == '#') board[i][j] = -1;
				else {
					// 초기 타겟 좌표 타겟 큐에 푸시 타겟판에 위치 1로 초기화
					if (c == '@') {
						Qs.push({ i, j });
						visS[i][j] = 1;
					}
					// 초기 불 위치 1로 초기화
					else if (c == '*') {
						Qf.push({ i, j });
						visF[i][j] = 1;
					}
					// 벽이 아니면 판 0으로 초기화
					board[i][j] = 0;
				}
			}
		}
		// 불 bfs 시작
		while (!Qf.empty()) {
			auto cur = Qf.front();
			Qf.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				// 판 밖이면 탐색 중지
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				// 현재 탐색하는 곳이 벽이면 탐색 중지
				if (board[nx][ny] == -1) continue;
				// 이미 방문한 위치면 탐색 중지
				if (visF[nx][ny]) continue;
				// 불이 번지는 시간 카운트
				visF[nx][ny] = visF[cur.X][cur.Y] + 1;
				// 방문할 불 좌표 push
				Qf.push({ nx, ny });
			}
		}
		
		while ((!Qs.empty()) && (!escape)) {
			auto cur = Qs.front();
			Qs.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
					cout << visS[cur.X][cur.Y] << "\n";
					escape = true;
					break;
				}
				if (board[nx][ny] == -1) continue;
				if (visS[nx][ny]) continue;
				if (visF[nx][ny] != 0 && visF[nx][ny] <= visS[cur.X][cur.Y] + 1) continue;
				visS[nx][ny] = visS[cur.X][cur.Y] + 1;
				Qs.push({ nx, ny });
				
			}
		}
		
		// 여기까지 도달했다면 탈출 불가
		if (!escape) cout << "IMPOSSIBLE" << "\n";

	}

	return 0;
}
