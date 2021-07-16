#include <stdio.h>

void filecopy(FILE*, FILE*);

/* 简单的模拟cat 命令 */
int main(int argc, char *argv[]){
	FILE *fp;
	if(argc == 1){
		/* 没有参数默认为，输入打印到输出 */
		filecopy(stdin, stdout);
	}else{
		while(--argc > 0){
			if((fp = fopen(*++argv, "r")) == NULL){
				fprintf(stderr,"cat:can't open %s \n", *argv);
			} else {
				filecopy(fp, stdout);
				fclose(fp);
			}
		}
	}

	return 0;

}

void filecopy(FILE *ifp, FILE *ofp){
	int c;
	while((c = getc(ifp)) != EOF){
		putc(c, ofp);
	}
	putc('\n', ofp);
}