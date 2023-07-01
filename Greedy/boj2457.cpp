#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define	M first
#define D second

using namespace std;

int n;
int count;

vector<tuple<string,string,string>> v;

bool compare(const tuple<string, string, string>& a, const tuple<string, string, string>& b) {
	int numA = stoi(get<0>(a));
	int numB = stoi(get<0>(b));
	
	return numA < numB;
}


// 3월 1일부터 11월 29일까지 피어있는 꽃
// 무조건 한개이상의 꽃은 피어있어야한다.
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;




	while (n--) {
		string sm, sd, em, ed;
		cin >> sm >> sd >> em >> ed;
		v.push_back({ sm, sd , em + ed });
	}

	sort(v.begin(), v.end(), compare);

	for (auto i : v) {
		cout << get<0>(i) << get<1>(i) << " " << get<2>(i) << "\n";
	}

	return 0;
}
