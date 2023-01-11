#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string n;
	long long result = 0;

	cin >> n;
  // 내림차순 정렬
	sort(n.begin(), n.end(), greater<>());
  
  // 만약에 제일 끝 인덱스가 0이 아니면 -1 출력 10의 배수가 아니기때문에
	if (n[n.length() - 1] != '0')
		cout << -1;
	else {
		for (auto i : n)
			result += (i - '0');
    
    // 각 자리의 합이 3의 배수가 아니라면 이미 위에서 10의 배수를 판정했기때문에 배수판정법에 의해 30의 배수가아님 
		if (result % 3 == 0)
			cout << n;
		else
			cout << -1;
	}

	return 0;
}
