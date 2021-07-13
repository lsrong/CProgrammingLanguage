
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MaxOp 100		/* 最大操作数 */
#define Number '0'		/* 数字类型 */
#define MaxVal 100		/* 最大栈数 */
#define BufSize 100		/* 输入缓冲区大小 */

int sp =0;				/* 下一个栈位置 */
double val[MaxVal]; 	/* 数栈：先进后出 */

char buf[BufSize]; 		/* 缓冲区 */
int bufp = 0;			/* 下一个空闲的缓冲位置 */

void push(double f);
double pop(void);

int getop(char s[]);
int getch(void);
void ungets(char s[]);
void ungetch(char c);

int main(int argc, char *argv[])
{
	double op1,op2;
	char s[MaxOp];
	while(--argc > 0){
		ungets(" ");
		ungets(*++argv);
		switch(getop(s)){
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
			default:
				printf("error:unkown command(%s)\n", s);
				break;
		}
	}

	printf("\t%.8g\n", pop());
	return 0;
}


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


/* getch:获取一个字符，提前获取缓存区，没有才获取输入 */
int getch(void)
{
	return (bufp > 0)? buf[--bufp]:getchar(); 
}

void ungetch(char c)
{
	if(bufp >= BufSize){
		printf("ungetch: too many characters\n");
	}else{
		buf[bufp++] = c;
	}
}

void ungets(char s[])
{
	int len = strlen(s);
	while(len > 0){
		ungetch(s[--len]);
	}
}

/* getoop:读取操作符号和操作数,考虑负数问题 */
int getop(char s[])
{
	int i,c;
	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;

	// 非数字,操作符号
	if(!isdigit(c) && c != '.' && c != '-'){
		return c;
	}


	// 负数问题
	if(c == '-'){
		if(isdigit(c = getch()) || c == '.'){
			// 为数字，例如：-2 
			s[++i] = c;
		}else{
			// 减号，缓存并返回
			if(c !=EOF){
				ungetch(c);
			}
			return c;
		}
	}

 	// 数字
	if(isdigit(c)){
		while(isdigit(s[++i] = c = getch()))
			;
	}

	if(c == '.'){
		while(isdigit(s[++i] = c = getch()))
			;
	}
	s[i] = '\0';
	if(c != EOF){
		ungetch(c);
	}

	return Number;
}



