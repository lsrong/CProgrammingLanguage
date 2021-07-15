#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MaxLen 100
#define Lines 100
#define Default 10

void error(char *);
int getLine(char *, int);

/* 编写程序tail,将输入中的最后n行打印出来，默认情况下 n的值为10，通过可选参数改变n的值： tail -100 */
int main(int argc, char *argv[]){
	char *p;
	char *buf;
	char *bufend;
	char line[MaxLen];
	char *lineptr[Lines];
	int n, i, first, last, nlines, len;


	// 参数处理
	if(argc == 1){
		n =Default;
	}else if(argc == 2 && (*++argv)[0] == '-'){
		n = atoi(argv[0]+1);
	}else{
		error("Usage: tail [-n]");
	}
	// 超过限制的n
	if(n < 1 || n > Lines){
		n = Lines;
	}

	// 初始化每行
	for(i = 0;i< Lines; i++)
		lineptr[i] = NULL;

	/* 分配内存 */
	if((p = buf = malloc(Lines * MaxLen)) == NULL)
		error("tail: cannot allocate buf");

	// 指针最大值
	bufend = buf + Lines * MaxLen;
	last = 0;
	nlines = 0;
	while((len = getLine(line, MaxLen)) > 0){
		
		// 缓存最大长度判断
		if(p + len + 1 >= bufend){
			p =buf;
		}
		
		lineptr[last] = p;
		strcpy(lineptr[last], line);
		if(++last >= Lines)
			last = 0;
		p += len+1;
		nlines++;
	}

	if(n > nlines){
		n = nlines;
	}
	first = last - n;
	if (first < 0)
		first += Lines;

	// 往后循环输出值
	for(i=first; n-- >0;i = (i+1) %Lines){
		printf("%s", lineptr[i]);
	}

	return 0;
}


void error(char *s){
	printf("%s\n", s);
	exit(1);
}

int getLine(char *l, int lim){
	int c;
	char *t = l;
	while(--lim > 0 && (c = getchar()) != EOF && c != '\n'){
		*l++ = c;
	}
	if( c == '\n'){
		*l++ = c;
	}

	*l = '\0';
	return l - t;
}