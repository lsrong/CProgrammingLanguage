#include <stdio.h>
void sort(int v[], int left, int right);
void swap(int v[], int i, int j);

int main()
{
	int num[10] = {432,5321,432,445,5325,32,55234,324,63,234};
	int i = 0;
	sort(num, 0, 9);
	while(i < 10){
		printf("%d\n", num[i++]);
	}
	return 0;
}

/* 
	sort: 快速排序算法
	从数组中选择一个元素，以该元素为界将其余元素划分为两个子集，一个子集中的所有元素小于该元素，另一个子集中的所有元素大于或者等于该元素。
	对这样的子集递归执行这一过程，当某个子集中的元素小于2时，这个子集就不需要再次排序，终止递归。
 */
void sort(int v[], int left, int right)
{
	int i , last;

	/* 结束语句：集合里面元素数量小于2 */
	if(left >= right){
		return;
	}
	/* 选中间元素为界限，小于的mid的放在左边，大于的放在右边 */
	swap(v, left, (left + right) / 2);
	last = left;
	for(i = left +1; i <=right; i++){
		if(v[i] < v[left]){
			swap(v, ++last, i);
		}
	}

	// 恢复中间元素到两边的边界位置
	swap(v, left, last);
	sort(v, left, last-1);
	sort(v, last+1, right);
}

void swap(int v[], int i, int j)
{
	int t;
	t = v[i];
	v[i] = v[j];
	v[j] = t;
}