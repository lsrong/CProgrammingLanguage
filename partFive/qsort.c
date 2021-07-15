#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Numeric 1 /* 数字标识： 00000001 */
#define Desc 2	/* 排序标识：00000010 */

#define Lines 100
#define MaxLen 1000


int numcmp(char *s, char *t);
int getLine(char *s, int max);
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines, int desc);
void swap(char *v[], int i, int j);
void sortSelf(char *v[], int left, int rignt, int(*comp)(void *, void *));

static char option = 0; /* 默认为： 00000000 */

/* 修改排序程序，能处理-r标记，以逆序（递减）方式排序，保证能和-r，-n组合一起使用 */
int main(int argc, char *argv[]){
	int nlines;
	char *lineptr[Lines];
	int c, rc =0;

	// 处理参数: sort -rn
	while(--argc > 0 && (*++argv)[0] == '-'){
		// 内循环读取 rn字符
		while(c = *++argv[0]){
			switch(c){
			case 'n':
				option |= Numeric;
				break;
			case 'r':
				option |= Desc;
				break;
			default:
				printf("sort:illegal option %c \n", c);
				argc = 1;
				rc =-1;
				break;
			}
		}
	}

	if(argc > 0){
		printf("Usage: sort -nr\n");
		return rc;
	}


	if((nlines = readlines(lineptr, Lines)) > 0){
		if(option & Numeric){
			sortSelf((void**)lineptr, 0, nlines-1, (int(*)(void*, void*))numcmp);
		}else{
			sortSelf((void**)lineptr, 0, nlines-1, (int(*)(void*, void*))strcmp);
		}

		writelines(lineptr, nlines, option & Desc);
	}else{
		printf("input too big to sort\n");
		rc = -1;
	}

	return rc;
}



int numcmp(char *s1, char *s2){
	double v1, v2;
	v1 = atof(s1);
	v2 = atof(s2);
	if(v1 < v2){
		return -1;
	}else if(v1 > v2){
		return 1;
	}else{
		return 0;
	}
}

/* swap：交换两个下标的值 */
void swap(char *v[], int i, int j){
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void sortSelf(char *v[], int left, int right, int(*comp)(void *, void *)){
	int i, last;
	if(left >= right){
		return;
	}
	swap(v, left, (left + right)/2);
	last = left;
	for(i = left+1; i <= right; i++){
		if((*comp)(v[i], v[left]) < 0){
			swap(v,++last, i);
		}
	}
	swap(v, left, last);
	sortSelf(v, left, last-1, comp);
	sortSelf(v, last+1, right, comp);
}

/* getLine:读取一行字符 */
int getLine(char *s, int max){
	int c;
	char *t = s;
	while(--max>0 && (c = getchar()) != EOF  && c != '\n'){
		*s++ = c;
	}
	if(c == '\n'){
		*s ++ = c;
	}
	*s = '\0';

	return s - t;
}

/* readlines：读取所有的行数 */
int readlines(char *lineptr[], int maxlines){
	int len, nlines;
	char *p, line[MaxLen];
	nlines = 0;
	while((len = getLine(line, MaxLen)) > 0){
		 p= malloc(sizeof(len));
		if(nlines >= maxlines || p == NULL){
			return -1;
		}else{
			line[len-1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

/* writelines:打印所有行数 */
void writelines(char *lineptr[], int nlines, int desc){
	int i;
	if(desc){
		for(i = nlines-1; i >=0;i--)
			printf("%s\n", lineptr[i]);
	}else{
		for(i = 0; i < nlines; i++)
			printf("%s\n", lineptr[i]);
	}
	
}

