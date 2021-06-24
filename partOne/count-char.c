# include <stdio.h>

// 统计空格，制表符，换行符个数
int main(){
	int ns, nt, nn, c;
	ns = nt = nn = 0;
	while((c = getchar()) != EOF){
		if(c == '\n'){
			++nn;
		}else if(c == '\t'){
			++nt;
		}else if(c == ' '){
			++ns;
		}
		printf("ns = %d, nt = %d, nn = %d \n", ns, nt, nn);

	}

	return 0;
}