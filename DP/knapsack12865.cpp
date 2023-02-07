#include <iostream>
using namespace std;

int DP[101][100001];
int w[101];
int v[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

	// 물건의 순서 행 (i번째 물건까지)
    for (int i = 1; i <= n; i++) { 
		// 넣을 수 있는 최대 무게 열
        for (int j = 1; j <= k; j++) { 
			// 현재 물건이 배낭에 들어갈 수 없는 경우 이전 가치를 그래도 사용
            if (w[i] > j)
                DP[i][j] = DP[i - 1][j]; 
			// 현재 물건이 배낭에 들어갈 수 있으면 이전 가치와 비교를 하여 둘중 더 큰 가치를 사용
            else
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - w[i]] + v[i]);
        }
    }

    cout << DP[n][k];

    return 0;
}
