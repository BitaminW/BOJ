#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, int> ntime;
pair<int, int> arr[100001];

int cnt;
/*
	반례
	3
	3 3
    3 4
    1 3

    Ans : 3
    output : 2
	끝나는 시간이 같을 경우 시작하는 시간을 오름차순 정렬해야함
	만약 3 - 3  1 - 3 방문시에 끝나는 시간이 같음에도  3 - 3을 먼저
	방문하기 떄문에 1 - 3을 배정할 수 없음
	if (a.second == b.second) return a.first < b.first;
*/
bool compare(pair<int,int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ntime.first >> ntime.second;

		arr[i].first = ntime.first;
		arr[i].second = ntime.second;
	}

	sort(arr, arr + n, compare);

	int last = 0;
		
	for (int i = 0; i < n; i++) {
		if (last <= arr[i].first) {
			last = arr[i].second;
			cnt++;
		}
	}

	cout << cnt;
	
	return 0;
}


