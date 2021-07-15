#include <stdio.h>
#include <stdlib.h>

#define MaxLine  100
#define TabInc 8
#define Yes 1
#define No 0

void settab(int argc, char *argv[], char *tab);
void entab(char *tab);
void detab(char *tab);
int tabpos(int pos, char *tab);

int main(int argc, char *argv[]){
	char tab[MaxLine +1];

	/* 根据参数设置停止制表符 */
	settab(argc, argv, tab);

	/* 数组tab对应的是一行字符，每个元素对应着文本行的一个位置。如果文本行的某个位置是一个制表符停止位，与之对应的元素取值为Yes，否则为No */
	/* Yes为制表符位,No为正常符号 */
	// entab(tab);
	detab(tab);

	return 0;
}

/* settab: 设置指标符号 */
void settab(int argc, char *argv[], char *tab){
	int i,pos;
	// 没有参数情况
	if(argc <= 1){
		for(i=1;i<= MaxLine; i++)
			if(i%TabInc == 0)
				tab[i] = Yes;
			else
				tab[i] = No;

		return;	
	}

	// 有传参,将制定位置设置为制表符停止位
	for(i = 1; i <= MaxLine; i++)
		tab[i] = No;
	while(--argc){
		pos = atoi(*++argv);
		if(pos>0 && pos <= MaxLine){
			tab[pos] = Yes;
		}
	}
}

/* entab: 转换tab */
void entab(char *tab){
	int c, pos;
	int nb = 0;
	int nt = 0;
	// 条件多个条件判断使用for
	for(pos =1; (c = getchar()) != EOF; pos++){
		if(c == '*'){
			if(tabpos(pos, tab) == No){
				++nb;
			}
			else{
				nb = 0;
				++nt;
			}
				
		}else{
			/* 打印制表符 */
			while(nt >0){
				putchar('\t');
				--nt;
			}

			if(c == '\t'){
				nb = 0;
			}else{
				for(;nb >0; nb--){
					putchar('*');
				}
			}
			putchar(c);
			if(c == '\n'){
				pos = 0;
			}else if (c == '\t'){
				while(tabpos(pos, tab) != Yes){
					++pos;
				}
			}

		}
	}
}


/* detab:转义tab制表符 */
void detab(char *tab){
	int c, pos;
	pos = 1;
	while((c = getchar()) != EOF){
		if(c == '\t'){
			do{
				putchar('*');
			} while(tabpos(pos++, tab) != No);

		}else if (c == '\n'){
			putchar(c);
			pos =1;
		}else{
			putchar(c);
			++pos;
		}
	}
}


/* tabpos: 判断当前位置是否为制表符停止位 */
int tabpos(int pos, char *tab){
	if(pos > MaxLine){
		return Yes;
	}else{
		return tab[pos];
	}
}


