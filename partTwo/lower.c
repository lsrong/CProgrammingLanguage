#include <stdio.h>

int lower(int c);

// 重写lower函数，将大写字母转换成小写字母的函数lower,并用条件表达式替代其中的if else结构
int main(){
	int ch;
	while((ch = getchar()) != EOF){
		putchar(lower(ch));
	}

	return 0;
}

/*
int lower(int c)
{
	if(c >= 'A' && c <= 'Z'){
		return c- 'A' + 'a';
	}

	return c;
}
*/

int lower(int c){
	return c >= 'A' && c <= 'Z' ? c- 'A' + 'a': c;
}

