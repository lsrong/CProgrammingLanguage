#include <stdio.h>

void inComment(void);
void inQuote(int c);
void search(int c);

int brace, brack, paren;

// 查找C语言程序中的基本语法错误，如圆括号，方括号以及花括号不配对。正确处理引号，转义符号以及注释。
/*
思路：
	1. 利用符号是成对出现的原理，给圆括号，方括号以及花括号出现次数计数，左边出现加1，右边出现减1，结束输入应该都为0，否则为语法错误
	2. 注意跳过注释，引号内容
	3. 未结束的输入之前计数出现正数是可能出现的情况，因为后面可能存在结束符号，但是出现负数则不能允许，没有开始符号。
*/
int main(){
	int ch;
	extern int brace, brack, paren;
	while((ch = getchar()) != EOF){
		if(ch == '/'){
			if((ch = getchar()) == '*'){
				// 跳过注释
				inComment();
			}else{
				search(ch);
			}
		}else if(ch == '\'' || ch == '"'){
			inQuote(ch);
		}else{
			search(ch);
		}

		// 不允许出现负数，正数是允许出现的，因为接下来可能找到与之匹配的符号
		if(brace < 0){
			printf("非法花括号‘{}’");
		}else if(brack < 0){
			printf("非法中括号‘[]’");
		}else if(paren < 0){
			printf("非法括号‘()’");
		}
	}

	// 结束的时候出现正式也是不对的，因为输入已经结束，没有找到与之匹配的右边符号
	if(brace > 0){
		printf("非法花括号‘{}’");
	}else if(brack > 0){
		printf("非法中括号‘[]’");
	}else if(paren > 0){
		printf("非法括号‘()’");
	}
}

/* 跳过注释内容 */
void inComment(void){
	int c,d;
	c = getchar();
	d = getchar();
	while(c != '*' || d != '/'){	//找到结束符号
		c = d;
		d = getchar();
	}
}

/* 跳过引号内容 */
void inQuote(int c){
	int ch;
	while((ch = getchar())!= c){
		if(ch == '\\'){
			getchar();
		}
	}
}

/* 利用括号，方括号， 花括号成对出现的特性，左边符号加1, 右边符号减1 */
void search(int c){0
	extern int brace,brack,paren;
	if(c == '{')
		++brace;
	else if(c == '{')
		--brace;
	else if(c == '[')
		++brack;
	else if(c == ']')
		--brack;
	else if(c == '(')
		++paren;
	else if(c == ')')
		--paren;
}