#include <stdio.h>

/* 	
	argc:参数数量（至少为1），第一个参数为命令名称
	argv:指向字符串数组的指针
*/
int main(int argc, char *argv[])
{
	/* argv,字符指针数据 */
	int i;
	for(i=1; i< argc; i++){
		printf("%s%s",argv[i],(argc-i > 0) ? " ": "");
	}
	printf("\n");
	
	return 0;


	/* argv的指针自增实现 */
	while(--argc > 0){
		printf("%s%s", *++argv, (argc-1) > 0 ? " ": "");
	}

	printf("\n");

	return 0;
}