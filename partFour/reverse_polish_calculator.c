#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MaxOp 100		/* 最大操作数 */
#define Number '0'		/* 数字类型 */
#define MathName 'n'	/* */
#define MaxVal 100		/* 最大栈数 */
#define BufSize 100		/* 输入缓冲区大小 */

int sp =0;				/* 下一个栈位置 */
double val[MaxVal]; 	/* 数栈：先进后出 */

char buf[BufSize]; 		/* 缓冲区 */
int bufp = 0;			/* 下一个空闲的缓冲位置 */

void push(double f);
double pop(void);
void clear(void);

int getop(char s[]);
int getch(void);
void ungetch(int ch);

void mathfnc(char func[]);
/*
在逆波兰表示法中，所有运算符都跟在操作数的后面。比如，下列中缀 表达式:
(1 – 2) * (4 + 5) 
采用逆波兰表示法表示为: 
1 2 - 4 5 + *
逆波兰表示法中不需要圆括号，只要知道每个运算符需要几个操作数就不会引起歧义。

每个操作数都被依次压入到栈中;
当一个运算符到达时，
从栈中弹出相应数目的操作数(对二元运算符来说是两个操作数)，
把该运算符作用于弹出的操作数，并把运算结果再压入到栈中。
例如，对上面的逆波兰表达式来说，
首先把 1 和 2 压入到栈中，再用两者之差-1 取代它们;
然后将 4 和 5 压入到栈中，再用两者之和9 取代它们。 
最后，从栈中取出校顶的-1 和 9，并把它们的积 -9 压入到栈顶。到达输入行的末尾时，把栈顶 的值弹出并打印。

操作：
while (下一个运算符或操作数不是文件结束指示符) 
	if (是数) 
		将该数压入到找中 
	else if (是运算符) 
		弹出所需数目的操作数 执行运算 将结果压入到找中 
	else if (是换行符) 
		弹出并打印找顶的值
	else 
		出错

*/

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

/* getch:获取一个字符，提前获取缓存区，没有才获取输入 */
int getch(void)
{
	return (bufp > 0)? buf[--bufp]:getchar(); 
}

/* ungetch:将已知的输入缓存在缓存区中为下一次读取使用 */
void ungetch(int c)
{
	if(bufp >= BufSize){
		printf("ungetch: too many characters\n");
	}else{
		buf[bufp++] = c;
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
	if(islower(c)){
		while(islower(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if(c != EOF){
			ungetch(c);
		}
		if(strlen(s) > 1){
			return MathName;
		}else{
			return c;
		}
	}


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



