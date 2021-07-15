#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MaxWord 100

struct tnode{
	char *word;
	int count;
	struct tnode *left;	/* 结构体自引用 */
	struct tnode *right; 
};



struct tnode *talloc(void);
char *strDup(char *);
struct tnode *addTree(struct tnode *, char *);
void treePrint(struct tnode *);
int getWord(char *, int);

int main(){
	struct tnode *root;
	char word[MaxWord];

	root =NULL;
	while(getWord(word, MaxWord) != EOF){
		if(isalpha(word[0]))
			root = addTree(root, word);
	}
	treePrint(root);
	return 0;
}

/* talloc:分配内存 */
struct tnode *talloc(void){
	return (struct tnode *) malloc(sizeof(struct tnode));
}

/* strDup:复制字符串 */
char *strDup(char *s){
	char *p;
	p = (char *)malloc(strlen(s) + 1);
	if (p != NULL){
		strcpy(p, s);
	}
	return p;
}

/* addTree: 递归插入二叉节点树 */
struct tnode *addTree(struct tnode *p, char *w){
	int cond;
	if (p == NULL){
		p = talloc();
		p->word = strdup(w);
		p->count = 1;
		p->left = p ->right = NULL;
	}else if((cond = strcmp(w, p->word)) == 0){
		p->count++;
	}else if(cond < 0){
		p->left = addTree(p->left, w);
	}else{
		p->right = addTree(p->right, w);
	}

	return p;
}


/* treePrint:打印二叉树结构 */
void treePrint(struct tnode *p){
	if(p != NULL){
		treePrint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treePrint(p->right);
	}
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

