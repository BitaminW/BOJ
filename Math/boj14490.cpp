#include <bits/stdc++.h>

using namespace std;

int sol(int a, int b) {
	int r = a % b;
	if (r == 0) {
		return b;
	}
	return sol(b, r);
}
string s,n,m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int index = 0;
	string n, m;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ':') {
			index = i;
			break;
		}
	}
	n = s.substr(0, index);
	m = s.substr(index + 1, s.length());
	
	int num = sol(stoi(n), stoi(m));

	cout << stoi(n) / num << ":" << stoi(m) / num;
	
	return 0;
}
