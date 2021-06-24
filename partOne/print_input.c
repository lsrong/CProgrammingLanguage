# include <stdio.h>
	
# define Match 10	// 长度限制常量
# define MaxLine 1000 	// 限定行的长度

int getLine(char line[], int max);
void echo(char line[]);

// 打印长度大于80个字符的输入行
int main()
{
	int n;	// 输入行长度
	char line[MaxLine];


	while((n = getLine(line, MaxLine)) > 0){
		if(n > Match)
			echo(line);
	}

	return 0;
}

// 获取一行
int getLine(char line[], int max)
{
	int c, n;
	n =0;
	while((c = getchar()) != EOF && c != '\n' && n < max-1){
		line[n] = c;
		++n;
	}

	if(c == '\n'){
		line[n] = c;
		++n;
	}
	line[n] = '\0';

	return n;
}

void echo(char line[])
{
	int i;
	for(i =0; line[i] != '\0'; i ++)
		putchar(line[i]);
}