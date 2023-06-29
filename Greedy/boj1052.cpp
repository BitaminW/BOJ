#include <iostream>

using namespace std;

int n, k;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;		

	if (k >= n) {
		cout << 0;
	}
	else {
		int result = 0;

		while (1) {
			int count = 0;
			int tmp = n;
			while (tmp > 0) {
				if (tmp % 2 == 0) {
					tmp /= 2;
				}
				else {
					tmp /= 2;
					count++;
				}
			}
			if (k >= count) {
				break;
			}

			n++;
			result++;
		}
		cout << result;
	}

	return 0;
}
