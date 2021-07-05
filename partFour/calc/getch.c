#include <stdio.h>
#include "calc.h"

#define BufSize 100		/* 输入缓冲区大小 */

char buf[BufSize]; 		/* 缓冲区 */
int bufp = 0;			/* 下一个空闲的缓冲位置 */

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