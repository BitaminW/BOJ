#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string board[27];
int vis[27][27];
vector<int> v;
int n, cnt;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	
	for(int i = 0; i < n; i++){
			cin >> board[i];
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			// 이미 방문한 칸이거나 빈공간이면 탈출
			if(board[i][j] == '0' || vis[i][j] == 1){
				continue;
			}

			queue<pair<int,int>> q;
			int width = 1;

			//방문표시
			vis[i][j] = 1;
			q.push({i, j});
			cnt++;

			while(!q.empty()){
				auto cur = q.front(); q.pop();

				for(int dir = 0; dir < 4; dir++){
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					// board 범위 밖이면 탈출
					if(nx < 0 || nx >= n || ny < 0 || ny >= n){
						continue;
					}
					//이미 방문한 칸이거나 빈공간이면 탈출
					if(board[nx][ny] == '0' || vis[nx][ny] == 1){
						continue;
					}
					q.push({nx, ny});
					vis[nx][ny] = 1;
					width++;
				}
			}
			v.push_back(width);
		}
	}
	cout << cnt << "\n";
	sort(v.begin(), v.end());

	for(auto i : v){
		cout << i << "\n";
	}
	return 0;
}
