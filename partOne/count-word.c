#include <stdio.h>

# define IN 1
# define OUT 0
# define MAXWORDLEN 10

int vertical(int graph[], int length);

int horizontal(int graph[], int length);

// 编写一个程序,打印输入中单词长度的直方图.水平方向的直方图比较容易绘制,垂直方向的直方图则比较困难
int main(){
	int i,ch, state;
	int wordLen = 0; 	// 统计每个单词长度
	int overflow = 0; 	// 超过单词最大长度的数量
	int wordGraph[MAXWORDLEN];	// 每个指定长度数量单词出现次数

	// 初始化单词统计数组
	for(i =0; i < MAXWORDLEN; ++i){
		wordGraph[i] = 0;
	}

	// 单词数量出现的次数
	state = OUT;
	while((ch = getchar()) != EOF){
		// 遇到空格，制表符，判断是否在单词内，如果单词内则为一个单词的结束
		if(ch == ' ' || ch == '\n' || ch == '\t'){
			if(state == IN){
				if(wordLen <= MAXWORDLEN){
					++wordGraph[wordLen];
				}else{
					++overflow;
				}
				wordLen = 0;
				state =OUT;
			}

		}else{
			state = IN;
			++wordLen;
		}
	}
	putchar('\n');

	// 打印水平直方图
	// horizontal(wordGraph, MAXWORDLEN);

	// 打印垂直直方图
	vertical(wordGraph, MAXWORDLEN);


	printf("There are %d words >= %d\n", overflow, MAXWORDLEN);


	return 0;
}

int vertical(int  graph[], int length){
	int i, j ,max;
	// 最大值
	max =0;
	for (i = 0; i < length; ++i){
		if(graph[i] >= max){
			max = graph[i];
		}
	}

	//从最大值开始打印
	for(i = max; i > 0; --i){
		for(j =1; j < length; j++){
			if(graph[j] >= i){
				printf("*  ");
			}else{
				printf("   ");
			}
		}
		putchar('\n');
	}


	// 
	for(j =1; j < length; ++j){
		printf("%-3d", graph[j]);
	}

	putchar('\n');

	for(j =1; j < length; ++j){
		printf("%-3d", j);
	}
	putchar('\n');

	return 0;

}


int horizontal(int graph[], int length){
	int i,j, len;
	for(i= 1;i < length; ++i ){
		printf("%5d - %5d:", i, graph[i]);
		len = graph[i];
		while(len > 0){
			putchar('*');
			--len;
		}
		putchar('\n');
	}
	return 0;
}