#include <bits/stdc++.h>

using namespace std;

int a, n;
int arr[51];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	if (n == 1) {
		// ex) n = 1 이고 약수 2일경우 2 * 2 = 4
		// n = 1  약수가 5 일경우 5 * 5 = 25 임으로 제곱해야함
		cout << arr[0] * arr[0];
		return 0;
	}
	else {
		cout << arr[0] * arr[n - 1];
	}

	return 0;
}
