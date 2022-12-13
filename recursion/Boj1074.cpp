#include <bits/stdc++.h>

using namespace std;

int func(int n, int r, int c) {
	if (n == 0) return 0;
	// 절반 ,한변 절반의 길이 왜냐하면 사각형을 4개로 나누면 한변의 절반을 알아야
	// 1번 사각형인지 2번인지 3번인지 4번인지 알수가 있기때문임.
	int half = 1 << (n - 1); 
	
	// 첫번째 .행과 열의 인덱스가 절반의 길이보다 작아야함 
	if(r < half && c < half) return func(n - 1, r, c);
	
	// 두번째 .행의 인덱스가 절반의 길이보다 작고 열은 같거나 커야 2번째 사각형 
	if (r < half && c >= half) return half * half + func(n - 1, r, c - half);
	
	// 세번째 행의 인덱스가 절반의 길이보다 크고 열은 작아야 3번째 인덱스임
	if (r >= half && c < half) return 2 * half * half + func(n - 1, r - half, c);
	return 3 * half * half + func(n - 1, r - half, c - half);

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, r, c;
	cin >> n >> r >> c;
	cout << func(n, r, c);

	return 0;
}
