#include <iostream>
#include <algorithm>
using namespace std;

int n, result;
int a[51], b[51];

// b 의 제일 큰 수를  a의 가장 작은수로 곱한다.
// b 배열은 재배열하면 안 된다지만 결과값만 내는 것이기 때문에 상관없음

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	sort(a, a + n);
	sort(b, b + n, greater<int>());

	for (int i = 0; i < n; i++) {
		result += a[i] * b[i];
	}
	
	cout << result;
	return 0;
}
