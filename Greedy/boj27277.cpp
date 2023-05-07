#include <bits/stdc++.h>

using namespace std;

int n, arr[100002], res;

// (실력이 제일 높은 학생 - 실력이 제일 낮은 학생) 짝으로 놓는게 가장 높은 실력을 발휘함
// 6
// 1 4 3 5 6 2
// 6 1 5 2 4 3

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n, greater<>());

    res = arr[0];

    for(int i = 1; i < n; i++){
        
        if(i > (n / 2)){
            break;
        }
        res += (arr[i] - arr[n - i]);
    }

    cout << res;

    return 0;
}
