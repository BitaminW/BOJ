#include <bits/stdc++.h>

#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

using namespace std;

int board[302][302];
int vis[302][302];
int row, col;
int year;


bool check(int x, int y){
    // board 밖이 아니라면 true 리턴
    return (x >= 0 && x < row && y >= 0 && y < col); 
}

void melt(){
    int temp[302][302] = {0};  // 임시 배열 초기화
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col;){
            if(board[i][j] == 0) continue; // 만약 빙산이 없을 경우 종료
            for(int dir = 0; dir < 4; dir++){
                int cx = i + dx[dir];
                int cy = j + dy[dir];
                // board 밖이 아니거나 빙산이 없다면 
                if(check(cx, cy) && board[cx][cy] == 0)
                    temp[i][j]++;
            }
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                board[i][j] = max(0, board[i][j] - temp[i][j]);
            }
        }
    }

}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> row >> col;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> board[i][j];
		}
	}

    while(1){
        year++;
        melt();
    }

    


	return 0;
}
