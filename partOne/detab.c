# include <stdio.h>

# define TabNum 8	// tab空格数量
# define MaxInputNum 1000 	// 最大输入字符	
// 编写程序detab，将输入中的制表符替换成适当数目的空格，使空格充满到下一个制表符终止位的地方
// 假如tab的为8个空格，则需要计算转变成空格的数量 (tabnum - pos -1) % tabnum , 大于0才需要填充  12\t34 : 12      34， 终止为下一个制表符
/*
int main(){
	char ch;
	char input[MaxInputNum];
	int pos, index, number;
	index = 0;
	pos = 0;
	while((ch = getchar()) != EOF){
		if(ch == '\t'){
			number = (TabNum - pos) % TabNum;
			while(number > 0){
				input[index] = ' ';
				++index;
				--number;
			}
			pos=0;
		}else if(ch == '\n'){
			input[index] = ch;
			pos = 0;
			++index;
		}else{
			input[index] = ch;
			++index;
			++pos;
		}
	}

	printf("detab: %s\n", input);

	return 0;
}
*/

int main()
{
	int pos, nb;
	char ch;
	pos = 0;
	while((ch = getchar())  != EOF){
		if(ch == '\t'){
			// 计算填充的空格
			nb = (TabNum - pos) % TabNum;
			while(nb > 0){
				// 需要填充空格
				putchar(' ');
				++pos;
				--nb;
			}
		}else if(ch == '\n'){
			// 换行, 重新计算开始位置
			putchar(ch);
			pos = 0;
		}else{
			// 其他字符
			putchar(ch);
			++pos;
		}
	}

	return 0;
}