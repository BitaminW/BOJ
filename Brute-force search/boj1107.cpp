#include <bits/stdc++.h>

using namespace std;

int t;
int m[10];
string n;

bool check(int now) {
	string s = to_string(now);
	for (int i = 0; i < s.length(); i++) {
		if (m[s[i] - 48]) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> t;

	for (int i = 0; i < t; i++) {
		int tmp;
		cin >> tmp;
		m[tmp]++;
	}
	
	if ( stoi(n) == 100 ) {
		cout << 0;
		return 0;
	}
	
	int ans = abs(stoi(n) - 100);

	for (int i = 0; i <= 1000000; i++) {
		if (check(i)) {
			int tt = abs(stoi(n) - i) + to_string(i).length();
			ans = min(ans, tt);
		}
	}
	cout << ans << "\n";
	return 0;
}


