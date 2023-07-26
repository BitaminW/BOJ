/* 0 및 양의 정수 집합을 배열로 구현하려고 한다. 집합은 원소들이 모두 유일하다는 특성을 가진다.
정수의 집합에 임의의 원소를 추가하려고 할 떄, 이미 있는 원소이면 추가하지 않고 0을 출력하고 
새로운 원소가 추가된 경우에는 1을 출력하는
프로그램을 작성하여라. 입력은 음수가 입력될 떄 가지 받도록 한다. 최초의 입력은 음수가 아니라고 가정한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>


int arr[101];
char str[102];
int cnt;
bool swap = true;

int main() {
	
	int temp;
	
	for (int i = 0; i < 100; i++) {
		scanf("%d", &temp);
		
		if (temp < 0)
			break;

		arr[i] = temp;
		cnt++;
	}

	str[0] = '1';

	for (int i = 1; i < cnt; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] == arr[j]) {
				str[i] = '0';
				swap = false;
				break;
			}
		}
		if (swap) {
			str[i] = '1';
		}
		swap = true;
	}

	printf("%s", str);

	return 0;
}
