#include <stdio.h>
#include "calc.h"

#define MaxVal 100		/* 最大栈数 */

int sp =0;				/* 下一个栈位置 */
double val[MaxVal]; 	/* 数栈：先进后出 */

/*push: 压栈*/
void push(double f){
	if(sp < MaxVal){
		val[sp++] = f;
	}else{
		printf("error: stack full, can't push %g\n", f);
	}
}

/* pop: 出栈 */
double pop()
{
	if(sp > 0){
		return val[--sp];
	}else{
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* clear: 清空栈 */
void clear(void)
{
	sp = 0;
}
