#include <stdio.h>

void recomment(int c);
void inComment(void);
void echoQuote(int c);



// 删除C语言程序中所有的注释语句。要正确处理带引号的字符串与字符常量。在C语言中，注释不允许嵌套
// 本题只删除注释/**/语句, 默认输入的为合法的C语言
/*  注释内容 */   
int main(){
	int ch;
	while((ch = getchar()) != EOF){
		recomment(ch);
	}

	return 0;
}

/* 注释标识辨别:读取每一个字符，移除注释内容 */
void recomment(int c)
{
	int next;

	if(c == '/'){
		next = getchar();
		if (next == '*'){
			// 注释的开始:/* ..删除注释.. */
			inComment();
		}else if(next == '/'){
			putchar(c);
			recomment(next);
		}else{
			// 不是注释
			putchar(c);
			putchar(next);
		}

	}else if(c == '\'' || c == '"'){
		/* 带引号的字符串与字符常量 */
		echoQuote(c);
	}else{
		// 不是注释
		putchar(c);
	}
}

/* 查找注释结束位置**
*  */
void inComment(void)
{
	int c,d;
	c = getchar();	// 前一字符
	d = getchar();	// 当前字符
	while(c != '*' || d != '/'){	// c == '*' && d == '/'
		c = d;
		d = getchar(); // 跳过注释内容
	}
}

/* 输出单，双引号内容 */
void echoQuote(int c)
{
	int d;
	putchar(c);

	// 查找结束引号
	while((d = getchar()) != c){
		putchar(d);
		// 跳过转移符号
		if(d == '\\'){
			putchar(getchar());
		}
	}
	putchar(d);
}
