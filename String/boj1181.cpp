#include <bits/stdc++.h>

using namespace std;
int n;
string word[20002];

bool Solution(string a, string b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	else {
		return a < b;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> word[i];
	}

	sort(word, word + n, Solution);

	string before = "";
	for (int i = 0; i < n; i++) {
		if (before == word[i]) continue;
		cout << word[i] << "\n";
		before = word[i];
	}

	return 0;
}
