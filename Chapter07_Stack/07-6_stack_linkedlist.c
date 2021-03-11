typedef struct stackNode_t
{
	int value;
	struct stackNode_t *next;
} StackNode;

void StackPush(StackNode **ptrHead, int value)
{
	StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
	if (!temp) {
		printf("메모리 할당 오류");
		return;
	}
	temp->value = value;
	temp->next = *ptrHead;
	*ptrHead = temp;
}

int StackPop(StackNode **ptrHead)
{
	StackNode *deleteMe;
	int value;
	if (*ptrHead) {
		deleteMe = *ptrHead;
		*ptrHead = deleteMe->next;
		value = deleteMe->value;
		free(deleteMe);
		return value;
	}
	else {
		printf("스택이 비었습니다.\n");
		return ERROR_VALUE;
	}
}


/* test code */
int main()
{
	StackNode *head = NULL;
	StackPush(&head, 1);
	StackPush(&head, 2);
	StackPush(&head, 3);
	StackPush(&head, 4);
	StackPush(&head, 5);
	for (int i = 0; i < 5; i++) {
		printf("%d", StackPop(&head));
	}
	return 0;
}
