#include <stdio.h>

#define MaxChar 10000

void excape(char s[], char t[]);
void unexcape(char s[], char t[]);

// 编写一个函数escape(s, t),将字符串t复制到s中，并将换行，制表符等显示为\n,\t等相应的转义符号。
int main(){
	char s[MaxChar], t[MaxChar];
	char ch;
	int i;
	i = 0;
	while((ch = getchar()) != EOF && i < MaxChar){
		t[i++] = ch;
	}

	excape(s, t);
	printf("input: %s\n", s);


	return 0;
}


void excape(char s[], char t[])
{
	int i,j;
	for(i = j = 0; t[i] != '\0'; i++){
		switch(t[i]){
		case '\n':
			s[j++] = '\\';
			s[j++] = 'n';
			break;
		case '\t':
			s[j++] = '\\';
			s[j++] = 't';
			break;
		default:
			s[j++] = t[i];
			break;
		}
	}
	s[j] = '\0';
}

void unexcape(char s[], char t[])
{
	int i, j;
	for(i = j =0; t[i] != '\0'; i++){
		if(t[i] == '\\'){

		}else{
			s[j++] = t[i];
		}
	}

	s[j] = '\0';
}