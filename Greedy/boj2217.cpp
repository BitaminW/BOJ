#include <bits/stdc++.h>

using namespace std;

int n, max_, cur;
int arr[100001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n, greater<>());
    
    // 최대 들 수 있는 무게
    max_ = arr[0];
    
    for (int i = 1; i < n; i++) {
        cur = arr[i] * (i + 1);    // i번째 로프까지 들 수 있는 최대 무게
        // 현재 들 수 있는 최대 무게가 기존 최대 무게보다 크다면 교체
        if (cur > max_) {
            max_ = cur;
            continue;
        }
    }
    cout << max_;
    return 0;
}



