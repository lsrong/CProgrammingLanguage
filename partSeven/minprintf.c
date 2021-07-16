#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

#define LOCALFMT  100

void minprintf(char *fmt, ...);

int main(){
	minprintf("hello %s!", "world");
}

/* 实现简化的printf函数;可变参数，printf,参数类型标识 */
void minprintf(char *fmt, ...){
	va_list ap;	/* 变长参数 */
	char *p, *sval;
	char localfmt[LOCALFMT];
	int i, ival;
	unsigned uval;
	double dval;
	va_start(ap, fmt);

	for(p = fmt; *p; p++){
		if(*p != '%'){
			putchar(*p);
			continue;
		}
		/* 取printf的fmt字符串：%d,%.10d,... */
		i=0;
		localfmt[i++] = '%';
		while(*(p+1) && !isalpha(*(p+1)))
			localfmt[i++] = *++p;

		localfmt[i++] = *(p+1);
		localfmt[i] = '\0';

		/* 打印字符 */
		switch(*++p){
		case 'd':
		case 'i':
			/* 整型 */
			ival = va_arg(ap, int);
			printf(localfmt, ival);
			break;
		case 'x':
		case 'X':
		case 'u':
		case 'o':
			uval = va_arg(ap, unsigned);
			printf(localfmt, uval);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf(localfmt, dval);
			break;
		case 's':
			sval = va_arg(ap, char *);
			printf(localfmt, sval);
			break;
		default:
			printf(localfmt);
			break;

		}
	}

	va_end(ap);


}