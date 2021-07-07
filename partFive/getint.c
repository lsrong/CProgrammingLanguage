#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int n);
int getint(int *);

/* 将标识是否达到文件结尾的状态作为getint函数的返回值，使用一个指针参数存储转换后得到的整数并传回给主调函数。 */
int getint(int *pn)
{
	int c, d, sign;
	while(isspace(c = getch()))
		;
	
	/* 非数字 */
	if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if(c == '+' || c == '-'){
		d = c;	/* 记录数值 */
		if(!isdigit(c = getch())){
			if(c != EOF){
				ungetch(c);	/* 非整数，放入缓存 */
			}
			ungetch(d);	/* 符号标识放入缓存 */
			return d;
		}
	}
	for(*pn = 0; isdigit(c); c = getch()){
		*pn = 10 * *pn + (c - '0');
	}

	*pn *= sign;
	if (c != EOF){
		ungetch(c);
	}

	return c;

}