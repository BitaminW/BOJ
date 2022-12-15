#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
bool isused[10];

void sol(int k) {
	// base condition 
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int start = 1;
	if(k != 0){ start = arr[k - 1] + 1;}

	for (int i = start; i <= n; i++) {
		if (!isused[i]) {
			arr[k] = i;
			isused[i] = true;
			sol(k + 1);
			isused[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	
	sol(0);
  
	return 0;
}
