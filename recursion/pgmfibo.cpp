#include <bits/stdc++.h>

// 메모이제이션 적용
long long da[100001];

int solution(int n) {
    long long answer = 0;

    if (n <= 2) {
        return 1;
    }
    if (da[n] != 0) {
        return da[n];
    }
    else {
      // n번째수가 longlong 범위를 넘어가기 떄문에
      // return answer % 1234567; 이 불가능
      // (A + B) % C의 값은 ( ( A % C ) + ( B % C) ) % C와 같다는 성질을 이용
        da[n] = (solution(n - 1) + solution(n - 2)) % 1234567;
    }
    answer = da[n];
    return answer;
}
