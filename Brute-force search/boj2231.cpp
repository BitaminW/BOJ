#include <iostream>
#include <cstring>

using namespace std;

int main() {

	int n;
    std::cin >> n;
    // 숫자자릿수부터 계산
    int m = n;
    int digit = 0;

    while (m){
        m /= 10;
        digit++;
    }
    
    char s[10];
    int sum = 0;
	bool flag=false;

    // 시작 지점 (ex 256일 경우 256 - 3 * 9 = 229부터 탐색) 
    // 각 자리수에 들어갈 수는 가장 커봐야 9 이기 떄문에 3자리 수일경우 9 , 9 , 9
    // 생성자는 n - 각자리수의 최대합보다 항상 크거나 같다. 
    int begin = n - digit * 9;

    for (int i = begin; i <= n; ++i)
    {
        sprintf(s, "%d", i);
        sum = i;
		for(int j=0; j < strlen(s); ++j)
			sum += s[j]-'0';        // 아스키코드 0 을 빼준다.
        if(sum == n )
		{
			flag = true;
			cout << i;
			break;
		}
    }
	if(flag==false)	cout << "0";

	return 0;
}
