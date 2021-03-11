int StackPop(Stack *stk)
{
	if (stk->top >= 0) {
		int value = stk->data[stk->top];
		stk->top--;
		if (stk->top < (stk->capacity / 2) && stk->capacity > stk->min) {
			stk->capacity = stk->capacity / 2;
			stk->data = (int *)realloc(stk->data, sizeof(int) * (stk->capacity));
			printf("스택 크기가 반으로 줄었습니다.\n");
			printf("스택 용량 %d\n", stk->capacity);
		}
		return value;
	}
	printf("스택이 비었습니다.\n");
}