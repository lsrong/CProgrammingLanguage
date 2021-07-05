#include <stdio.h>
#include <stdlib.h>

void printd(int n);
void itoa(int n, char s[]);

int main()
{
	printd(1);
	printf("\n");

	char s[10];
	itoa(-100, s);
	printf("itoa:%s\n", s);

	return 0;
}

/* printd:打印数字 */
void printd(int n)
{	
	// 负数
	if(n < 0){
		putchar('-');
		n = -n;
	}

	if(n / 10){
		printd(n / 10);
	}

	putchar(n % 10 + '0');
}

/* itoa: 整型转换成字符串 */
void itoa(int n, char s[]){
	// 静态变量
	static int i;
	if(n / 10){
		itoa(n/10, s);
	}else{
		i = 0;
		if(n < 0){
			s[i++] = '-';
		}
	}
	s[i++] = abs(n) % 10 + '0';
	s[i] = '\0';
}
