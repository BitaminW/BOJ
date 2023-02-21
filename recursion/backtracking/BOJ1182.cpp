#include <iostream>

using namespace std;

int n, s, cnt, temp;
int arr[21];

void dfs(int c, int t) {
	if (c == n) {
		if (t == s) // 합이 s라면 카운트
			cnt++;
		return;		// 아니라면 리턴
	}

	dfs(c + 1, t);
	dfs(c + 1, t + arr[c]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dfs(0, 0);
	if (s == 0) cnt--;
	cout << cnt;
	return 0;
}
