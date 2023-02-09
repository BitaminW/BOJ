#include <iostream>

using namespace std;

long long s;
long long n, sum, num = 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	// 1부터 더해서 s를 넘어갈 때까지 연산
	// 넘어갈 경우 현재까지 더한 수의 개수(n) - 1
	while (1) {
		sum += num;
		n++;
		if (sum > s) {
			break;
		}
		num++;
	}

	cout << n - 1;
	return 0;
}


