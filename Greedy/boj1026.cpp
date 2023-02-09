#include <iostream>
#include <algorithm>
using namespace std;

int n, result;
int a[51], b[51];

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
