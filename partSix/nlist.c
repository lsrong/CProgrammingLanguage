#include <string.h>
#include <stdlib.h>			

#define  HASHSIZE 101

struct nlist
{
	struct nlist *next;	/* 链表后继指针 */
	char *name; /* 指向名称指针 */
	char *defn; /* 替换文本指针 */
};

static struct nlist *hashtab[HASHSIZE]; /* 散列表 */

struct nlist *lookp(char *);
struct nlist *install(char *, char *); 
unsigned hash(char *);

/* hash:从一个字符串中生成hash值 */
unsigned hash(char *s){
	unsigned hashval;
	for(hashval = 0; *s != '\0'; s++){
		hashval = *s + 31 * hashval;
	}

	return hashval % HASHSIZE;
}

/* lookup:从散列表中查找某个字符串 */
struct nlist *lookup(char *s){
	struct nlist *np;
	for(np = hashtab[hash[s]]; np != NULL; np = np->next){
		if(strcmp(s, np->name) == 0){
			return np;
		}
	}

	return NULL;
}

/* install:借助lookup判断名称是否存在，如果存在则用新定义取代，不存在则创建新表 */
struct nlist *install(char *name, char *defn){
	struct nlist *np;
	unsigned hashval;

	if((np = lookup(name)) == NULL){ /* 没找到，创建 */
		np = (struct nlist *)malloc(sizeof(*np));
		if(np == NULL || (np->name = strdup(name)) == NULL){
			return NULL;
		}
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}else{
		/* 找到，释放替换字符 */
		free((void *)np->defn);
	}

	if((np->defn = strdup(defn)) == NULL){
		return NULL;
	}
	return np;
}






