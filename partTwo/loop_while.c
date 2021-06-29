#include <stdio.h>

#define MaxLine 1000


// 在不使用&&或者||的情况下编写与 for(i = 0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) 循环语句等价的循环语句
int main()
{
	int i, c;
	char line[MaxLine];
	// 原先语句： 
	// for(i=0; i < MaxLine-1 && (c =getchar()) != '\n' && c !=EOF; ++i){
	// 	line[i] = c;
	// }

	// 不使用 && 或者 || 的语句
	enum loop {YES, NO};
	enum loop okloop = YES;
	i = 0;
	while(okloop == YES){
		if(i >= MaxLine-1){
			okloop = NO;
		}else if((c = getchar()) == '\n'){
			okloop = NO;
		}else if(c == EOF){
			okloop = NO;
		}else{
			line[i] = c;
			++i;
		}
	} 

	line[i] = '\0'; 

	printf("line:%s\n", line);
}