/* 고정된 길이 배열로 구현된 stack */


typedef struct stack
{
	int top;
	int data[MAX_CAPACITY];
} Stack;

void StackInitialize(Stack *stk)
{
	stk->top = -1;
}

int StackIsEmpty(Stack *stk)
{
	return (stk->top == -1);
}

int StackSize(Stack *stk)
{
	return (stk->top + 1);
}

void StackPrint(Stack *stk)
{
	printf("Stack :: ");
	for (int i = stk->top; i >= 0; i--) {
		printf("%d ", stk->data[i]);
	}
	printf("\n");
}

void StackPush(Stack *stk, int value)
{
	if (stk->top < MAX_CAPACITY - 1) {
		stk->top++;
		stk->data[stk->top] == value;
	}
	else {
		printf("stack overflow\n");
	}
}

int StackPop(Stack *stk)
{
	if (stk->top >= 0) {
		int value = stk->data[stk->top];
		stk->top--;
		return value;
	}
	printf("stack empty\n");
	return ERROR_VALUE;
}

int StackTop(Stack *stk)
{
	int value = stk->data[stk->top];
	return value;
}


/* test code */
int main()
{
	Stack stk;
	StackInitialize(&stk);
	StackPush(&stk, 1);
	StackPush(&stk, 2);
	StackPush(&stk, 3);
	StackPush(&stk, 4);
	StackPush(&stk, 5);
	StackPrint(&stk);
	return 0;
}
