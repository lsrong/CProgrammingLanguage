#define AllocSize 10000 /* 可用数组空间数量 */

static char allocbuf[AllocSize];	/* 存储数组 */
static char  *allocp = allocbuf;	/* 数组指针,下一个空闲的数组下标 */

/* 分配指定长度n的数组空间 */
char *alloc(int n)
{
	if(allocbuf + AllocSize - allocp >= n){
		allocp += n;
		
		return allocp - n;
	}

	return 0;
}

/* 释放存储指针到指针p的位置 */
void afree(char *p)
{
	if(p >= allocp && p < allocbuf + AllocSize){
		allocp = p;
	}
}