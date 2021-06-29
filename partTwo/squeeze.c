#include <stdio.h>

void squeeze(char s[], char q[]);

// 函数squeeze(s1,s2),将字符串s1中任何与字符串s2中字符匹配的字符都删除
int main(){

	char s[] = {'h', 'e','l', 'l', 'o', 'i'};
	char s2[] = {'l', 'e', 'o'};
	squeeze(s, s2);
	printf("squeeze:%s\n", s);	// 结果应该为 hi

	return 0;
}

/*
// 循环q,在s总存在有字符就删除
void squeeze(char s[], char q[])
{
	int i,j,k;
	for(k=0; q[k] != '\0'; ++k){
		for(i=j=0; s[i]!='\0'; ++i){
			if(s[i] != q[k])
				s[j++] = s[i];
		}
		s[j] = '\0';	
	}
}
*/

/* 官方：循环s,然后在q中找到有字符就删除，会减少q中重复的字符的循环次数 */
/*
	for(;表达式1;){
		if(表达式2){
			break;
		}
	}
	以上语句可以使用下面替换：
	for(;表达式1 && 表达式2;)
	;
*/
void squeeze(char s[], char q[])
{
	int i,j,k;
	for(i=j=0; s[i] != '\0'; ++i){
		for(k =0; q[k] != '\0' && s[i] != q[k];++k)
			;
		// 如果没有匹配到则q[k]应该为字符结束符号 ‘\0’
		if(q[k] == '\0')
			s[j++] = s[i];
	}
	s[j] = '\0';
}