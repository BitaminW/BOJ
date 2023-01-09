#include <bits/stdc++.h>
using namespace std;
int l, p, v, cnt, result, num = 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (true) {
		cin >> l >> p >> v;
		if (l == 0) break;
		
		result = ((v / p) * l);
		cnt = v % p;
		if (cnt > l) {
			cnt = l;
		}
		cout << "Case " << num << ": " << result + cnt << "\n";
		num++;
	}
	
	return 0;
}
