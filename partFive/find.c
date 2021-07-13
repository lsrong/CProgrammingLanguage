#include <stdio.h>
#include <string.h>

#define MaxLine 1000

int getLine(char *line, int max);

int main(int argc, char const *argv[])
{
	/* code */
	char line[MaxLine];
	long lineno = 0;
	int c,except = 1, number = 0, found = 0;
	
	/* *++argv是一个指向参数字符串的指引,(*++argv)[0]是参数字符串的第一个字符 */
	while(--argc > 0 && (*++argv)[0] == '-'){
		/* *++argv[0]：遍历参数字符串的值，*++argv[0]是对指正argv[0]的自增运算 */
		while(c = *++argv[0]){
			switch(c){
			case 'x':
				except=0;
				break;
			case 'n':
				number=1;
				break;
			default:
				printf("find: illegal option %c\n", c);
				argc = 0;
				found = -1;
				break;
			}
		}
	}

	if(argc != 1){
		printf("Usage:find -x -n pattern\n");
	}else{
		while(getLine(line, MaxLine) > 0){
			lineno++;
			if((strstr(line, *argv) != NULL) == except){
				if(number)
					printf("%ld:",lineno);
				printf("%s", line);
				found++;
			}
		}
	}

	return found;
}

/* getLine：字符串指针存储字符 */
int getLine(char *s, int lim)
{
	int c;
	// 第一个字符指针
	char *t = s;
	while(--lim > 0 && (c =getchar()) != EOF && c != '\n'){
		*s++ = c;
	}
	if (c == '\n'){
		*s++ = c;
	}
	*s = '\0';
	return s - t;
}

