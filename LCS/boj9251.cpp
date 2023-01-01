// 반례 찾기
/*
AAACATCGT

TACCTAAAA

ans : 4

wrong ans : 5

*/

#include <bits/stdc++.h>

using namespace std;

string s1,s2;
int lcs[1001][1001];
string result;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s1;
    cin >> s2;

    int maxl = max(s1.length(), s2.length());
    

    for(int i = 0; i <= maxl; i++){
        for(int j = 0; j <= maxl; j++){
            if(i == 0 || j == 0) lcs[i][j] = 0;
            // 두 문자가 같다면 lcs[i - 1][j - 1] 대각선 값에 +1을 함
            else if(s1[i] == s2[j])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
                // 두문자가 다르다면 lcs[i - 1][j], lcs[i][j - 1]중 큰 값을 집어넣음
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }
    
    cout << lcs[s1.length()][s2.length()];

    return 0;
}
