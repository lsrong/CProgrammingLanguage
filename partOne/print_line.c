#include <stdio.h>

# define MAXLINE 1000// 长度限制

int getLine(char line[], int max);
void copy(char to[], char from[]);

int main()
{
	int len;	// 当前行长度
	int max;	// 最长行的长度
	char line[MAXLINE];		// 当前输入行
	char longest[MAXLINE];	// 保存最长行

	while((len = getLine(line, MAXLINE)) > 0){
		printf("number of line is %d, line: %s\n", len, line);
		if(len > max){
			copy(longest, line);
			max = len;
		}
	}
	if(max >0){
		printf("number of the longest is %d, longest: %s\n", max,longest);
	}

	return 0;
}

int getLine(char line[], int max)
{
	int c;
	int i = 0;
	while((c = getchar()) != EOF && c != '\n' && i < max-1){
		line[i] = c;
		++i;
	}

	if(c == '\n'){
		line[i] = c;
		++i;
	}
	// 空字符，\0 标记字符串的结束
	line[i]  = '\0';

	return i;
}

void copy(char to[], char form[])
{
	int i = 0;
	while((to[i] = form[i]) != '\0')
		++i;

}
