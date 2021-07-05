#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "calc.h"

#define MaxOp 100		/* 最大操作数 */

int main()
{
	int type;
	double op1,op2;
	char s[MaxOp];
	while((type = getop(s)) != EOF){
		switch(type){
			case Number:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;	
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;	
			case '*':
				push(pop() * pop());
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0){
					push(pop() / op2);
				}else{
					printf("error: zero divisor \n");
				}
				break;
			case '%':
				op2 = pop();
				if(op2 != 0.0){
					push(fmod(pop() , op2));
				}else{
					printf("error: zero divisor \n");
				}
				break;
			case '?':	/* 打印最上层的值 */
				op2 = pop();
				printf("\t%.8g\n", op2);
				push(op2);
				break;
			case 'c':	/* 清空栈，sp位置，置空 */
				clear();
				break;
			case 'd': /* 复制顶层栈值 */
				op2 = pop();
				push(op2);
				push(op2);
				break;
			case 's': /* 交换上层两个元素,先进后出 */
				op1 = pop();
				op2 = pop();
				push(op1);
				push(op2);
				break;
			case MathName:
				mathfnc(s);
				break;
			case '\n':
				printf("%.8g\n", pop());
				break;
			default:
				printf("error:unkown command(%s)\n", s);
				break;
		}
	}
	return 0;
}

/* mathfnc:是否为函数名称  */
void mathfnc(char s[])
{
	double op2;
	if(strcmp(s, "sin") == 0){
		push(sin(pop()));
	}else if(strcmp(s, "cos") == 0){
		push(cos(pop()));
	}else if(strcmp(s, "exp") == 0){
		push(exp(pop()));
	}else if(strcmp(s, "pow") == 0){
		op2 = pop();
		push(pow(pop(), op2));
	}else{
		printf("error: %s not supperted\n", s);
	}
}