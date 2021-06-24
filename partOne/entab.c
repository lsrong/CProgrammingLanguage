# include <stdio.h>
# define MaxLine 1000 	// 每行最大数量
# define TabNum 8 	// 	tab对应的空格数量

int entab(char line[], int max);

// 编写程序entab，将空格串替换为最少数量的制表符和空格，但要保持单词之间的间隔不变
// 找出全部空格，pos递增到一个tabnum的时候空格传转换成制表符
// 遇到非空格符时，先打印积累起来的制表符和空格，空格和制表符重新设置为0，换行符号时候，pos重新开始计算
// 遇到制表符，只把积累的制表符和当前制表符打印
int main(){
	int c, nb, nt, pos;
	nb =0;	// 空格数量
	nt = 0 ;	// 制表符数量

	for(pos =1; (c = getchar()) != EOF; ++pos){
		if(c == '*'){
			if(pos%TabNum == 0){
				++nt;
				nb =0;
			}else{
				++nb;
			}
		}else{
			// 打印历史制表符
			while(nt > 0){
				putchar('\t');
				--nt;
			}
			// 打印历史空格，如果遇到制表符则不打印
			if(c == '\t'){
				nb =0;
			}else{
				while(nb > 0){
					putchar('*');
					--nb;
				}
			}
			putchar(c);
			// 换行重置位置，遇到制表符位置重新计算
			if(c == '\n'){
				pos = 0;
			}else if (c == '\t'){
				pos = pos + (TabNum - (pos -1) % TabNum) -1;
			}

		}
	}



	return 0;
}




/*
int main(){
	int n;
	char line[MaxLine];
	while((n =entab(line, MaxLine)) > 0){
		printf("%s", line);
	}
}
*/

int entab(char line[], int max)
{
	int i = 0;
	char ch;
	char last;
	int space = 0;
	while((ch = getchar()) != EOF && ch != '\n' && i < max-1){
		if(ch == '\t'){
			space = 0;
			line[i] = ch;
		}else if(ch == '*' && last == '*'){
			++space;
			if(space == TabNum){
				i = i - space+1;
				line[i] = '\t';
			}
		}else if(ch == '*'){
			space =1;
		}else{
			line[i] = ch;
		}
		last = ch;

		++i;
	}

	if(ch == '\n'){
		line[i] = ch;
		++i;
	}

	line[i] = '\0';
	return i;
}


