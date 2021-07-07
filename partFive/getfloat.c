#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int c);
int getfloat(float *);

/* 从输入中获取浮点型参数，传入指针参数保存转换的浮点数并传回给主调函数，类似于scanf的实现 */
int getfloat(float *pn)
{
	int c, sign;
	float power;
	while(isspace(c = getch()))
		;
	if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.'){
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if(c == '+' || c == '-'){
		c = getch();
	}
	for(*pn = 0.0; isdigit(c); c = getch()){
		*pn = 10.0 * *pn + (c - '0');	/*整数部分*/
	}
	if(c == '.'){
		c = getch();
	}
	/* 小数部分 */
	for(power = 1.0; isdigit(c); c = getch()){
		*pn = 10.0 * pn + (c - '0');
		power *= 10.0;
	}
	*pn *= sign/power;
	if (c != EOF){
		ungetch(c);
	}

	return c;
}