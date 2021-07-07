#include <stdio.h>
#include <string.h>
#define Max 1000

int getLine(char *s, int lim);
void reverse(char *s);
int strindex(char *s, char *t);
void itoa(int n, char *s);

int main(){
	char re[5] = "hello";
	char *r = re;
	reverse(r);
	printf("%s\n", r);

	char ns[3];
	char *pn = ns;
	int n = 100;
	itoa(n, pn);
	printf("%s\n", pn);

	char line[Max];
	char *s = line;
	while(getLine(s, Max) > 0){
		printf("%s", s);
	}

}

/* getLine：字符串指针存储字符 */
int getLine(char *s, int lim)
{
	int c;
	// 第一个字符指针
	char *t = s;
	while(--lim > 0 && (c =getchar()) != EOF && c != '\n'){
		*s++ = c;
	}
	if (c == '\n'){
		*s++ = c;
	}
	*s = '\0';
	return s - t;
}

/* reverse：反转字符 */
void reverse(char *s)
{
	int c;
	char *t;

	for(t = s + (strlen(s) - 1); s < t; s++, t--) {
		c = *s;
		*s = *t;
		*t = c;
	}
}

/* 指针运算代替下标 */
int strindex(char *s, char *t)
{
	char *b = s;
	char *p, *r;
	for( ; *s != '\0'; s++){
		for(p = s,r =t; *r !='\0' && *p == *r; p++, t++)
			;
		if(r > t && *r == '\0'){
			return s - b;
		}
	}

	return -1;
}

/* 整型转换成字符串 */
void itoa(int n, char *s){
	int sign;
	char *t = s;
	if((sign = n) < 0){
		n = -n;
	}
	do{
		*s++ = n % 10 + '0';
	}while((n/=10) > 0);
	if(sign < 0){
		*s++ = '-';
	}
	*s = '\0';

	reverse(t);
}