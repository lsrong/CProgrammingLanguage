#include <stdio.h>
#include <ctype.h>

#define MaxLine 1000


double atof(char s[]);
int getLine(char s[], int max);

/* 对 atof 函数进行扩充，
使它可以处理形如 123.45e-6 的科学表示法，
其中，浮点数后面可能会紧跟一个 e 或 E 以及一个指数 (可能有正负号)。 */
int main(){
	int ch;
	char line[MaxLine];
	while(getLine(line, MaxLine) > 0){
		printf("atof: %f\n", atof(line));
	}


	return 0;
}
int getLine(char s[], int lim)
{
	int i,ch;
	i = 0;
	while(--lim>0 && (ch = getchar()) != EOF && ch != '\n'){
		s[i++] = ch;
	}
	if (ch == '\n'){
		s[i++] = '\n';
	}
	s[i] = '\0';

	return i;
}

/* 字符串转为精度型，处理科学记数法：123.45e-6的情况*/
double atof(char s[])
{
	double val, power;
	int exp,i, sign;

	for(i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-')? -1: 1;
	if(s[i] == '+' || s[i] == '-'){
		i++;
	}
	// 计算整数
	for(val = 0.0; isdigit(s[i]); i++){
		val = val * 10 + (s[i] - '0');
	}

	// 计算小数点
	if(s[i] == '.'){
		i++;
	}

	for(power = 1.0;isdigit(s[i]); i++){
		val = val * 10 + (s[i] - '0');
		power *= 10.0;
	}
	// 非科学记数法在此就可以结束。
	// return sign * val / power; 
	val = sign * val / power;
	// exp获取科学计数的位数，-除以10，+乘以10
	if(s[i] == 'e' || s[i] == 'E'){
		sign = (s[++i] == '-') ? -1 : 1;
		if(s[i] == '+' || s[i] == '-'){
			++i;
		}
		// 计算科学计数
		for(exp = 0; isdigit(s[i]); ++i){
			exp = 10 * exp + (s[i] - '0');
		}
		if(sign == 1){
			// 正数
			while(exp-- > 0)
				val *= 10;
		}else{
			while(exp-- >0)
				val /= 10;
		}

	}
	return val;

}



