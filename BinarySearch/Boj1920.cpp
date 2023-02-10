#include <iostream>
#include <algorithm>

using namespace std;

int n, m, temp;
int arr[100001];

int biSearch(int target) {
	int st = 0;
	int en = n - 1;
	
	// start 와 end 가 교차되지 않을 때까지 반복
	while (st <= en) {
		// 중간 값
		int mid = (st + en) / 2;
		
		// 만약 찾는값이 배열의 중간값보다 크다면
		if (arr[mid] < target)
			st = mid + 1;	// 시작점을 중간 인덱스 +1로 옮김
		else if (arr[mid] > target)	// 중간값보다 작다면
			en = mid - 1;	// 끝지점을 중간 인덱스 -1로 옮김
		else
			return 1;	// 위 두 조건에도 걸리지않으면 arr[mid]와 target은 같음
	}
	return 0; // 교차 될 때까지 찾지 못했다면
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> temp;
		cout << biSearch(temp) << "\n";
	}
	return 0;
}
