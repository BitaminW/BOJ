#include <iostream>

using namespace std;

int n, result;
int board[16]; // 퀸은 1행당 하나밖에 둘 수 없기때문에 1차원 배열 선언

bool promising(int bc) {
	// 같은 행, 열 대각선에 퀸이 있다면 false 아니라면 true 반환
	for (int i = 0; i < bc; i++) {
		if (board[bc] == board[i] || bc - i == abs(board[bc] - board[i])) 
			return false;
	}
	return true;
}

void nQueen(int bc) {
	// 마지막 행까지 수행했다면
	// 마지막 행까지 수행해야하는 이유는 퀸이 있는 가로 세로 대각선에는
	// 둘수 없기 때문이다.
	if (bc == n) {
		// 경우의수 카운트
		result++;
		return;
	}

	// 보드판 N * N 까지만 수행
	for (int i = 0; i < n; i++) {
		// bc번째 행에 i번쨰열에 퀸을 하나씩 두어본다.
		board[bc] = i;
		// 해당 자리에  퀸을 두는게 두는게 가능하다면
		if (promising(bc))
			// 다음 행에 퀸을 놓아본다.
			nQueen(bc + 1);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	nQueen(0);
	cout << result;

	return 0;
}
