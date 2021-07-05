#include <stdio.h>
#include <string.h>

#define MaxLineNumer 1000

int getLine(char s[], int max);
int strIndex(char s[], char t[]);
int strrIndex(char s[], char t[]);
int sttrIndexOther(char s[], char t[]);

char pattern[] = "ould";

/* 编写一个程序，它将输入中包含特定"模式"或字符串 的各行打印出 来(这是 UNIX 程序 grep 的特例) */
/* 程序思路：
	while (还有未处理的行) 
		if (该行包含指定的模式) 
			打印该行
 */
int main(){
	int found, i;
	char ch;
	char line[MaxLineNumer];

	found = 0;
	while(getLine(line, MaxLineNumer) > 0){
		// if(strindex(line, pattern) >= 0){
		// 	printf("%s", line);
		// 	++found;
		// }
		// printf("%s", line);
		// printf("%d\n", strrIndex(line, pattern));
		if(strrIndex(line,pattern) >= 0){
			printf("%s", line);
			printf("%d\n", i);
			++found;
		}
	}

	return found; 
}

/* getline: 获取一行字符 */
int getLine(char s[], int max)
{
	int c, i;
	i = 0;
	/* 循环判断：考虑条件的优先级（表达式的权重），每个表达之间的关系（与，或，非） */
	while(--max > 0 && (c = getchar()) != EOF && c != '\n'){
		s[i++] = c;
	}

	if( c == '\n'){
		s[i++] = '\n';
	}

	s[i] = '\0';
	return i;
}

/* 检索字符串t在字符串s中首次出现的位置，存在则返回具体下标位置，不存在则返回-1 */
int strIndex(char s[], char t[])
{
	/* 
	查找的逻辑： 
	第一层循环遍历s中的字符作为二层循环的首个字符，
	第二层遍历t字符和外层循环首字符开始连续匹配，匹配上则返回i首个字符下标 
	*/
	int i,j,k;
	for(i =0 ; s[i] != '\0'; i++ ){
		for(j = i,k =0;t[k] != '\0' && s[j] == t[k]; j++, k++)
			;

		if(k > 0  && t[k] == '\0'){
			return i;
		}
	}
	return -1;
}

/* 第一种实现方式与strindex类似 */
/* 检索字符串t在字符串s中最后出现的位置，存在则返回最后出现的位置，不存在则返回-1 */
int strrIndex(char s[], char t[])
{
	int i, j , k, pos;
	pos = -1;
	for(i = 0; s[i] != '\0'; i++){
		for(j = i, k = 0; t[k] != '\0' && s[j]==t[k]; j++,k++)
			;
		if(k > 0 && t[k] == '\0'){
			pos = i;
		}
	}
	return pos;
}

/* 第二种实现: 从s字符串的末尾的t字符开始查找，依次向前寻找匹配，匹配到则返回位置 */
int sttrIndexOther(char s[], char t[])
{
	int i,j,k;
	for(i = strlen(s) - strlen(t); i >= 0; i--){
		for(j=i,k=0; t[k] != '\0' && s[j] == t[k]; j++,k++)
			;
		if(k > 0 && t[k] == '\0'){
			return i;
		}
	}
	

	return -1;
}
/* 第二种实现比第一种执行效率更高，
从尾部开始再向前推进字符串t的长度个字符开始寻找字符串t,
没有匹配到则从尾部向开始位置后退一个位置再次比较直到退到开始才结束。
只要找到有则退出，不需要逐个寻找
 */
