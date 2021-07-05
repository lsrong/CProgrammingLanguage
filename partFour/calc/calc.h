/* 声明头文件 */
#define Number '0'		/* 数字类型 */
#define MathName 'n'	/* 操作函数标识 */

/* 获取操作数 */
int getop(char s[]);
int getch(void);
void ungetch(int ch);

/* 操作数栈 */
void push(double f);
double pop(void);
void clear(void);

/* 操作函数 */
void mathfnc(char func[]);