# include <stdio.h>

int main(){
	// 将输入复制到输出，连续多个空格用一个空格
	/*
	int state, ch;
	while((ch = getchar()) != EOF){
		if(ch != ' ' || state != ' '){
			putchar(ch);

		}
		state = ch;
	}
	*/


	// 复制输入到输出，制表符替换成 \t， 回退符替换成\b 反斜杠替换为\\

	int ch;
	while((ch =getchar()) != EOF){
		if(ch == '\t'){
			putchar('\\');
			putchar('t');
		}else if(ch == '\b'){
			putchar('\\');
			putchar('b');
		}else if(ch == '\\'){
			putchar('\\');
			putchar('\\');
		}else{
			putchar(ch);
		}
	}


}