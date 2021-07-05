#include <stdio.h>
#include <ctype.h>
#include "calc.h"

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