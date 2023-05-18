#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, k = 1;
	scanf("%d", &n);
  
  // 1
  // 2 3
  // 3 4 5
  // 4 5 6 7
  // 5 6 7 8 9
	for (int i = 0; i < n; i++) {
		for (int j = k; j <= i + k; j++)
			printf("%d ", i + j);

		printf("\n");
	}

	return 0;
}
