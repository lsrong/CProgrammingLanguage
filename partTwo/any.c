#include <stdio.h>
#define NotFound -1

int any(char s[], char q[]);
// 编写函数any(s1,s2),将字符串s2中的任一字符在字符串s1中第一次出现的位置作为结果返回。如果是s1不包含说s2中的字符，则返回 -1
int main(){
	char s1[] = {'h', 'e','l', 'l', 'o'};
	char s2[] = {'l'};
	printf("any:%d\n", any(s1, s2));	// 结果应该为 2
}

int any(char s1[], char s2[])
{
	int i, j;
	for(i = 0; s1[i] != '\0'; ++i){
		for(j = 0; s2[j] != '\0' && s1[i] == s2[j]; ++j){
			return i;
		}
	}

	return NotFound;
}