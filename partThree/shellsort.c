# include <stdio.h>
# define Num 10

void shellsort(int v[], int n);


int main(){
	int i;

	int numbers[Num] = {43,4324,2,34,23,4,667,5435,3,0};
	shellsort(numbers, Num);
	for(i =0 ; i< Num; i++){
		printf("%d\n", numbers[i]);
	}	
}

// shell排序算法:
/* 
	第一层for循环控制两个被比较元素之间的距离，从n/2开始，逐步进行对折，直到距离为0
 	中间的for循环用于元素之间移动位置。
 	最内层的for语句用于比较各对相距gap个位置的元素
 */
void shellsort(int v[], int n){
	int gap, i, j, temp;
	for(gap = n/2; gap > 0; gap /=2 ){
		for(i = gap; i< n; i++){
			for(j = i-gap; j >= 0&& v[j] > v[j+gap]; j-=gap){
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
		}
	}
}