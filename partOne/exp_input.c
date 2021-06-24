#include <stdio.h>

#define MaxCol 10 // 对折位置
#define TabInc 8	// tab 空格数量

// 编写一个程序，把较长的输入行折成短一些的两行或者多行，折行的位置在输入行的第N列之前的最后一个非空格之后。
// 要保持程序能够智能地处理输入行很长以及在制定的列前没有空格或者制表符时的情况。
// 理解题意： 对输入行的每隔指定长度col对折，对折条件是col之前的第一个非空格，如果没有则删除输出空行
// 1. 保存对折的字符 char line[Col]， pos位置到达Col时进行对折
// 2. 对折条件：col之前的最后一个非空格符
// 3. 制表符需要转换成指定的空格数量
char line[MaxCol];	// 保存临时对折字符

int expTab(int pos); 	/* tab换成指定的长度的空格符 */
int findblnk(int pos);	/* 输入行pos开始往前找到非空格符号， 返回最后一个非空格符号的下标*/
void printl(int pos);	/* 打印对折字符 */
int newPos(int pos);	/* 重组line，存在后面的空格字符需要压栈到line中，计算开始位置 */

int main(){
	char ch;
	int pos;// 123456	78
	pos = 0;
	while((ch = getchar()) != EOF){
		line[pos] = ch;
		if(ch == '\n'){
			// 打印行；
			printl(pos);
			pos = 0;
		}else if (ch == '\t'){
			// 转换制表符为空格
			line[pos] = ' ';
		}else if(++pos >= MaxCol){
			// 到达对折长度， maxcol，需要对折字符。重置临时字符数组
			pos = findblnk(pos);
			printl(pos);
			pos = newPos(pos);
		}
	}

	return 0;
}

/* 打印对折字符 */
void printl(int pos)
{
	int i;
	for(i = 0; i < pos; ++i){
		putchar(line[i]);
	}

	if(pos > 0){
		putchar('\n');
	}
}

/* tab换成指定的长度的空格符 */
int expTab(int pos)
{
	// 默认tab转换成一个空格
	line[pos] = ' ';
	for(++pos; pos < MaxCol && pos%TabInc != 0; ++pos){
		line[pos] = ' ';
	}
	if(pos < MaxCol){
		return pos;
	}else{
		printl(pos);
		return 0;
	}
}

/* 输入行pos开始往前找到非空格符号， 返回最后一个非空格符号的下标 */
int findblnk(int pos){
	while(pos > 0 && line[pos] != ' '){
		--pos;
	}
	if(pos == 0){
		return MaxCol;
	}else{
		return pos;
	}
}

/* 重组line，存在后面的空格字符需要压栈到line中，计算开始位置 */
// 将最后面的字符调整到最前面字符。。。
int newPos(int pos){
	int i, j;
	if (pos <= 0 || pos >= MaxCol){
		return 0;
	}else{
		i = 0;
		// 最后面的字符重置到最前面
		for(j= pos; j < MaxCol; ++j){
			line[i] = line[j];
			++i;
		}
		return i;
	}

}