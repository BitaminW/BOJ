#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		string str;
		stack<char> S;
		cin >> str;
		for (auto c : str) {
			
			if (!S.empty()) {
				if ((c == ')') && (S.top() == '(')) {
					S.pop();
					continue;
				}
			}
			S.push(c);
		}
		if (S.empty()) {
			cout << "YES" << "\n";
			continue;
		}
		cout << "NO" << "\n";
	}

	return 0;
}
