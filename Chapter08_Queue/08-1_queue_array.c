/* ADT 
 * Add() 큐의 뒤에 원소를 하나 넣습니다.
 * Remove() 큐의 앞에서 원소를 하나 삭제합니다.
 * IsEmpty() 큐가 비어 있으면 1을 반한합니다.
 * Size() 큐의 원소 수를 반환합니다.
 */

#define MAX_CAPACITY 10
#define ERROR_VALUE -1

typedef struct Queue_t
{
	int front;
	int back;
	int size;
	int data[MAX_CAPACITY];
} Queue;

void QueueInitialize(Queue *que)
{
	que->back = 0;
	que->front = 0;
	que->size = 0;
}

void QueueAdd(Queue *que, int value)
{
	if (que->size >= MAX_CAPACITY) {
		printf("\n큐가 가득 찼습니다.");
		return;
	}
	else {
		que->size++;
		que->data[que->back] = value;
		que->back = (que->back + 1) % (MAX_CAPACITY - 1);
	}
}

/* Popleft */
void QueueRemove(Queue *que)
{
	int value;
	if (que->size <= 0) {
		printf("\n큐가 비었습니다.");
		return ERROR_VALUE;
	}
	else {
		que->size--;
		value = que->data[que->front];
		que->front = (que->front + 1) % (MAX_CAPACITY - 1);
	}
	return value;
}

int QueueFront(Queue *que)
{
	return que->data[que->front];
}

int QueueBack(Queue *que)
{
	return que->data[que->back -1 ];
}

int QueueRemoveBack(Queue *que)
{
	int value;
	if (que->size <= 0) {
		printf("\n큐가 비었습니다.");
		return ERROR_VALUE;
	}
	else {
		que->size--;
		value = que->data[que->back - 1];
		que->back = (que->back - 1) % (MAX_CAPACITY - 1);
	}
	return value;
}

int QueueIsEmpty(Queue *que)
{
	return que->size == 0;
}

int QueueSize(Queue *que)
{
	return que->size;
}
