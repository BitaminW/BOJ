#include <bits/stdc++.h>

using namespace std;

bool number[246913] = { false };

int max_sqrt = sqrt(246913);

void setPrime(bool* num) {
    num[0] = num[1] = true;

    for (int i = 2; i <= max_sqrt; i++) {
        if (num[i] == false) {
            for (int j = i + i; j <= 246912; j += i) {
                num[j] = true;
            }
        }
    }
}

int isPrime(int n) {
    int cnt = 0;
    for (int i = n + 1; i <= n * 2; i++) {
        if (!number[i]) {
            cnt++;
        }
    }


    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    setPrime(number);
    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }
        cout << isPrime(n) << "\n";
    }

    return 0;
}
