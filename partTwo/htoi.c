#include <stdio.h>
#define Num 5
#define YES 1
#define NO 0

int atoi(char s[]);
int htoi(char s[]);

// 编写函数htoi(),把由十六数字组成的字符串（包含可选的前缀0x或者0X)转换为与之等价的整数。字符串中允许包含的数字：0-9， a-f, A-F
int main(){
	char a[Num] = {'1','2','i', '4', '5'};
	printf("atoi:%d\n", atoi(a));	// 结果应该为12

	char h1[Num] = {'0', 'x', '6', '4'};
	printf("htoi:%d\n", htoi(h1));	// 结果应该为100

	char h2[Num] = {'2', '0', '8'};
	printf("htoi:%d\n", htoi(h2));	// 结果应该为520

	return 0;
}

/* 简单的字符串转成整型，不考虑小数 */
int atoi(char s[]){
	int i, n;
	n = 0;
	for(i = 0 ; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');

	return n; 
}


/* 由十六数字组成的字符串（包含可选的前缀0x或者0X)转换为与之等价的整数。字符串中允许包含的数字：0-9， a-f, A-F，不考虑小数 */
int htoi(char s[]){
	int n, i,hexdigit,mark;
	i = 0;
	// 1. 处理前缀0x或者0X
	if(s[i] == '0'){
		++i;
		if(s[i] == 'x' || s[i] == 'X'){
			++i;
		}
	}
	n =0;
	mark = YES;

	while(mark == YES){
		// 2. 判断字符是否在16进制字符
		if(s[i] >= '0' && s[i] <= '9'){
			hexdigit = s[i] - '0';
		}else if(s[i] >= 'a' && s[i] <= 'f'){
			hexdigit = 10 + (s[i] - 'a');
		}else if(s[i] >= 'A' && s[i] <= 'F'){
			hexdigit = 10 + (s[i] - 'A');
		}else{
			//非十六进制字符，结束循环
			mark = NO;
		}

		// 3. 十六进制转成十进制
		if(mark == YES){
			n = n * 16 + hexdigit;
		}

		++i;
	}

	return n;
}




