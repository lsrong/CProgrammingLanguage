# include <stdio.h>
# define IN 1
# define OUT 0

// 以每行一个单词的形式打印输入
int main(){
	int ch , state;
	state = OUT;
	while((ch = getchar()) != EOF){
		if(ch == ' ' || ch == '\n' || ch == '\t'){
			// 空字符
			if(state == IN){
				putchar('\n');
				state =OUT;
			}
		}else{
			putchar(ch);		
			state = IN;

		}
		
	} 
	
	return 0;
}