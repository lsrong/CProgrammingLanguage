# include <stdio.h>
# define MaxLine 1000

int getLine(char line[], int max);
int trim(char line[], int n);
int removeSpace(char line[]);

// 删除每个输入行末尾的空格，制表符，并删除完全是空格的行
int main(){
	int n,m, l;
	char line[MaxLine];
	while((n = getLine(line, MaxLine)) > 0){
		/*
		if((l = trim(line, n)) > 0 ){
			printf("input line: %s\n", line);
			printf("input number: %d\n", l);
		}*/
		if((l = removeSpace(line)) > 0){
			printf("input line: %s\n", line);
			printf("input number: %d\n", l);
		}


	}
	return 0;
}

int getLine(char line[], int max)
{
	int i, c;
	for(i = 0; (c = getchar()) != EOF && c != '\n' && i < max-1;++i){
		line[i] = c;
	}

	if (c == '\n'){
		line[i] = c;
		++i; 
	}

	line[i] = '\0';

	return i;
}

int trim(char line[], int n)
{
	int i;
	for(i = n -1; i >=0 ; --i){
		if(line[i] != ' ' && line[i] != '\t' && line[i] != '\n'){
			break;
		}
	}
	line[++i] = '\0';

	return i;
}

/* 去除末尾的空格是制表符 */
int removeSpace(char s[])
{
	int i;
	i = 0;
	// 统计行的字符长度
	while(s[i] != '\n'){
		++i;
	}
	--i;	// 去除 \n;
	// 从最后向前找 空格或者制表符
	while(i >= 0 && (s[i] == ' ' || s[i] == '\t')){
		--i;
	}
	// 长度大于o, 则不是空行，还有其他字符，需要打印
	if(i > 0){
		s[++i] = '\n';
		s[++i] = '\0';
 	}

	return i;
}