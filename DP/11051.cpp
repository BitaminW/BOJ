#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n,k;
ll dp[1001][1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    // 파스칼의 삼각형
    //    1
    //   1 1
    //  1 2 1
    // 1 3 3 1
    
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0) dp[i][j] = 1;
            else if(j == i) dp[i][j] = 1;
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
        }
    }

    cout << dp[n][k];

    return 0;
}
