/* 동적 메모리 할당
 * top : 꼭대기 원소의 인덱스
 * *data : 동적으로 할당된 메모리
 * size : 스택의 크기
 * capacity : 스택의 용량 */


typedef struct stack
{
	int top;
	int *data;
	int capacity;
	int min;
} Stack;

void StackInitialize(Stack *stk, int size)
{
	stk->data = (int *)malloc(sizeof(int) * size);
	stk->top = -1;
	stk->capacity = size;
	stk->min = size;
}