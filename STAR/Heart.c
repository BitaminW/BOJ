#include <stdio.h>
 
int main(){
	int i,j;
 
	for( i = 4 ; i < 10; i +=2 ){ 
		for( j = 0; j <= (10 - i); j++ ) printf(" ");
		for( j = 0; j <= i * 2; j++ ) printf("*");
		for( j = 0; j <= (10 - i) * 2; j++ ) printf(" ");
		for( j = 0; j <= i * 2; j++ ) printf("*"); 
		printf("\n"); 
	} 
	for( i = 20; i >= 0; i -= 2 ){ 
		for( j = 0;  j <= 20 - i; j++ ) printf(" ");   
		for( j = 0; j <= i * 2; j++ ) printf("*");
		printf("\n");
	} 

	return 0; 
}
