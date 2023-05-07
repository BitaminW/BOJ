#include <iostream>
#include <algorithm>

using namespace std;

int n, m, cards[101], result;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}

	sort(cards, cards + n, greater<int>());

	for (int i = 0; i < n-2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				int sum = cards[i] + cards[j] + cards[k];

				if (sum <= m) {
					result = max(result, sum);
				}

				if (result == m) {
					cout << result;
					return 0;
				}
			}
		}

	}
	cout << result;
	return 0;
}

