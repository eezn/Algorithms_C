void StackPush(Stack *stk, int value)
{
	if (stk->top < stk->capacity - 1) {
		stk->top++;
		stk->data[stk->top] = value;
		printf("value push : %d \n", value);
	}
	else {
		stk->capacity = stk->capacity * 2;
		stk->data = (int *)realloc(stk->data, sizeof(int) * (stk->capacity));
		printf("스택의 크기가 두 배가 되었습니다.\n");
		printf("스택 용량 %d\n", stk->capacity);
		StackPush(stk, value);
	}
}