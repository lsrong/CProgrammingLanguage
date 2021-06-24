# include <stdio.h>

int main(){
	int c;
	// EOF 默认 -1
	printf("%d",EOF);
	printf("%d\n", getchar()!=EOF);
	while((c = getchar()) != EOF){
		putchar(c);
	}


	return 0;
}