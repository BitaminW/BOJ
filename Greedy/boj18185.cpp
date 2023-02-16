#include <bits/stdc++.h>

using namespace std;

int a[10004];
int n;
int result;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        // 만약 3개를 샀을 때 더 손해를 본다면
        // case  1 2 1 1
        if (a[i + 1] > a[i + 2]) {
            // 두개만 산다.
            int two = min(a[i], a[i + 1] - a[i + 2]);
            result += 5 * two; 
            // 구매한 개수를 뺀다
            a[i] -= two;  a[i + 1] -= two;

            // 3개를 산다.
            int three = min(a[i], min(a[i + 1], a[i + 2]));
            result += 7 * three;
            // 구매한 개수를 뺀다
            a[i] -= three; a[i + 1] -= three; a[i + 2] -= three;
        }
        // 위에 케이스가 아니라면 3개를 사야 이득이라면
        else {
            int three = min(a[i], min(a[i + 1], a[i + 2]));
            result += (7 * three);

            a[i] -= three; a[i + 1] -= three; a[i + 2] -= three;
            
            // 세개를 구매한 후에 2개를 구매해야 이득인 경우
            // case 2 1 1 1
            int two = min(a[i], a[i + 1]);
            result += 5 * two;
            a[i] -= two;
            a[i + 1] -= two;
        }
        // 한개만 사야하는 경우를 모두 더해준다.
        result += 3 * a[i];
    }
    cout << result << "\n";
    return 0;
}


/*
    반례
    wrong
    1 2 1 1
    0 1 0 1     => 7
    0 0 0 1     => 10
    0 0 0 0     => 13

    correct
    1 2 1 1
    0 1 1 1     => 5
    0 0 0 0     => 12
*/





