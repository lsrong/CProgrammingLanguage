# include <stdio.h>

# define STEP   20

# define UPPER  300
# define LOWER  0



int main(){
	// 摄氏温度与华氏温度转换表（0~300） F = (9/5)*C
	int fahr1, celsius;
	celsius = LOWER;
	printf("C\tF\n");
	while(celsius <= UPPER){
		fahr1 = (9 * celsius)/5 + 32;
		printf("%d\t%d\n", celsius, fahr1);
		celsius = celsius + STEP;
	}


	// 华氏温度与摄氏温度转换表（300~0） C = (5/9)(F - 32)
	int fahr2;
	printf("F\tC\n");
	for(fahr2 = UPPER; fahr2 >= LOWER; fahr2 = fahr2 - STEP){
		printf("%d\t%.1f\n", fahr2, (5.0/9.0)*(fahr2-32));
	}


	return 0;

}


