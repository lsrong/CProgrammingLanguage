# include <stdio.h>
# include <string.h>

# define Max 1000	// 最大字符数

void reverseOne(char line[]);
void reverseTwo(char line[]);
void reverseThree(char line[]);
int getLine(char line[], int max);
// 编写reverse(s)函数，将字符串s中的字符颠倒过来，使用该函数，每次颠倒输入行的字符顺序
int main()
{
	int l;
	char line[Max];
	while((l = getLine(line, Max)) > 0){
		// reverseOne(line);
		// reverseTwo(line);
		reverseThree(line);
		printf("reverse line:%s\n", line);
	}


	return 0;
}


int getLine(char line[], int max)
{
	int i, c;
	for(i = 0; (c = getchar()) != EOF && c != '\n' && i < max-1;++i){
		line[i] = c;
	}

	line[i] = '\0';

	return i;
}

// 第一种实现方式：划分一般字符数，兑换前半段和后半段字符
void reverseOne(char line[]){
	int i,n;
	char temp;
	n = 0;
	while(line[n] != '\0'){
		++n;
	}
	--n;

	for(i = 0; i <= n/2; ++i){
		temp = line[i];
		line[i] = line[n-i];
		line[n-i] = temp;
	}
}


// 官方：两个下标值，第一个和最后一个下标相互兑换: i：为最后一个字符下标，j：第一个字符下标
void reverseTwo(char s[]){
	int i, j;
	char temp;

	// 总数
	i = 0;
	while(s[i] != '\0'){
		++i;
	}
	--i;	// 去除 \n
	j=0;	// 开始字符下标
	while(j < i){
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		++j;
		--i;
	}
}

/* for循环实现对调 */
void reverseThree(char s[]){
	int c, i, j;
	for(i=0,j=strlen(s)-1;i < j; i++, j-- ){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
 	}

}