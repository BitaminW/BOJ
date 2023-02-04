#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int dp[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}

	int result = dp[0];

	for (int i = 1; i < n; i++) {
		// 1번인덱스부터 시작
		dp[i] = max(dp[i], dp[i - 1] + arr[i]);
		// 최대합 계산
		if (dp[i] > result) {
			result = dp[i];
		}
	}

	cout << result << "\n";

	return 0;
}
