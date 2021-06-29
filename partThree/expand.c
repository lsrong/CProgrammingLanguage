#include <stdio.h>
#define Num 100

void expand(char s[], char t[]);

int main()
{
	char s1[] = "a-z0-9";
	char s2[Num];
	expand(s1, s2);
	printf("%s\n", s2);
}

/* 扩展类似 a-z一类的速记符号在字符串s2中 */
void expand(char s1[], char s2[])
{
	int c ,i ,j;
	i = j = 0;
	while((c = s1[i++]) != '\0'){
		if(s1[i] == '-' && s1[i+1] >= c){
			// 处理 c1-c2
			i++;
			while(c < s1[i]){
				s2[j++] = c++;
			}


		}else{
			s2[j++] = c;
		}
	}

	s2[j] = '\0';
}

