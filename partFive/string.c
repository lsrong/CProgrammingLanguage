#include <stdio.h>

void strcpy(char *, char *);
void strncpy(char *, char *, int n);
void strcat(char *, char *);
void strncat(char *, char *, int n)
void strend(char *, char *);

/* strcpy：复制字符串 */
void strcpy(char *s, char *t)
{
	while(*s++ = *t++)
		;
}

/* strncpy: 复制t的前n个到字符串s中,t少于n就在末尾加上\0 */
void strncpy()
{
	while(*t && n-- > 0){
		*s++  = *t++;
	}
	while(n-- > 0){
		*s++ = '\0';
	}
}

/* strcat:指针运算追加字符串 */
void strcat(char *s, char *t){
	/* 循环递增指针到结尾 */
	while(*s)
		s++;
	/* 追加字符t到s */
	while(*s++ = *t++)
		;
}

void strncat(char *s, char *t, int n)
{
	int strlen(char *);
	strncpy(s*strlen(s), t, n);
}

/* strend:字符串t出现在字符串s的尾部，该函数返回1，否则返回0 */
void strend(char *s, char *t)
{
	char *bs = s;
	char *bt = t;

	/* 字符串s的末尾 */
	for( ; *s ; s++)
		;

	/* 字符串t的末尾 */
	for( ; *t; t++)
		;

	/* 从末尾开始判断元素是够相同，知道其中一个的开始 */
	for( ; *s == *t;s--, t--)
		if(t == bt || s == bs)
			break;
	
	if(*s == *t && t == bt && *s != '\0'){
		return 1;
	}else{
		return 0;
	}
}


