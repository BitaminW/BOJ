// string 으로 풀경우 string이 계속 복사가 일어나기때문에 char 배열로 처리하는것보다 훨씬 느림

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int recursion(const char* s, int l, int r, int* cnt) {
	(*cnt)++;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1, cnt);
}

pair<int, int> isPalindrome(const char* s) {
	pair<int, int> p;
	int cnt = 0;
	p.first = recursion(s, 0, strlen(s) - 1, &cnt);
	p.second = cnt;
	return p;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	char s[1002];

	cin >> t;
	while (t--) {
		cin >> s;
		cout << isPalindrome(s).first << " " << isPalindrome(s).second << "\n";
	}
}
