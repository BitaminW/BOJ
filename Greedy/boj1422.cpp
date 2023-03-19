#include <bits/stdc++.h>

using namespace std;

int k, n;
string karr;			// 문자열로 처리를 위한 string 선언
vector<string> ans;

// "10100" 이 "10010" 보다 크기때문에
// a + b , b + a 두개 중에 더 큰 수를 찾음
bool compare(string a, string b) {
	if (a + b > b + a) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;

	string str = "";	// 빈 문자열 선언

	for (int i = 1; i <= k; i++) {
		cin >> karr;

		// 가장 길이가 긴 숫자를 고르는 작업
		if (str.size() < karr.size() || str.size() == karr.size() && str < karr) {
			str = karr;
		}
		ans.push_back(karr);
	}

	// 제일 긴숫자를 이어 붙이는게 가장 큰수를 만들수 있기 때문에 제일 긴 숫자가 들어있는 str을 이어붙임
	for (int i = 0; i < n - k; i++) {
		ans.push_back(str);
	}

	// 자리수가 더 적다면 앞에두는게 더 큰숫자를 만들 수 있음. 오름차순 정렬
	sort(ans.begin(), ans.end(), compare);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}

	return 0;
}
