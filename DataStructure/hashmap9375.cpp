#include <bits/stdc++.h>

using namespace std;

int t,n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	
	while (t--) {
		cin >> n;
		map<string, int> m;
		while (n--) {
			string name,category;
			cin >> name >> category;
			if (m.find(category) == m.end())
				m.insert({ category, 1 });
			else
				m[category]++;
		}
		int ans = 1;
		for (auto i : m) {
			ans *= (i.second + 1);
		}
		cout << ans - 1 << "\n";
	}
	return 0;
}


