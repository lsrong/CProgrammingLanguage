#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
#define MaxWord 100
#define NKEYS (sizeof keytab / sizeof(keytab[0]))

struct key {
	char *word;
	int count;
};
struct key keytab[NKEYS];

int getWord(char *word, int lim);
int binSearch(char *, struct key *, int n);

int main(){
	// 获取单词，查找二分法单词，递增重复数量，打印结果
	int n;
	char word[MaxWord];
	while(getWord(word, MaxWord) > 0){
		if(isalpha(word[0])){
			if(n = binSearch(word, keytab, NKEYS) >=0){
				keytab[n].count++;
			}
		}
	}
	for(n =0; n < NKEYS; n++){
		if(keytab[n].count > 0){
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
		}
	}

	return 0;
}

/* binSearch:二分法查询已存在的单词 */
int binSearch(char *word, struct key tab[], int n){
	int cond;
	int low, high, mid;
	low = 0;
	high = n-1;
	while(low <= high){
		mid = (low+high) /2;
		if((cond = strcmp(word, tab[mid].word) < 0)){
			high = mid-1;
		}else if(cond > 0){
			low = mid+1;
		}else{
			return mid;
		}
	}

	return -1;
}

/* getWord：获取一个单词 */
int getWord(char *word, int lim){
	int c;
	char *w = word;
	while(isspace(c = getchar()))
		;
	if (c != EOF){
		*w++ = c;
	}

	if(!isalpha(c)){
		*w = '\0';
		return c;
	}
	for( ; --lim > 0;w++){
		if(!isalnum(*w = getchar())){
			break;
		}	
	}
	*w = '\0';

	return word[0];
}