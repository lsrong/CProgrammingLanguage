#include <stdio.h>
#include <string.h>
#define abs(x)	((x) < 0 ? -(x) : (x))

void itoa(int n, char s[]);
void reverse(char s[]);

int main(){
	char s[10];
	int n = 14324;
	itoa(n , s);

	printf("%s\n", s);
	return 0;
}
void itoa(int n,char s[])
{
	int i ,sign;
	sign = n;
	i = 0;
	do{
		s[i++] = abs(n) % 10 + '0';
	}while((n /= 10) != 0);
	if(sign < 0){
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]){
	int i,j, temp;
	for(i = 0, j = strlen(s) -1; i < j; i++, j--){
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}