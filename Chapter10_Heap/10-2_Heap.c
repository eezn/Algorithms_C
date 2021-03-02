/* array 힙을 저장하는 데 사용 */
/* capacity 배열의 용량 */
/* size 배열의 원소 수 */
/* isMinHeap 최소 힙일 때 1, 최대 힙일 때 0 */

typedef struct Heap
{
	int capacity;
	int size;
	int *array;
	int isMinHeap;
} Heap;

int HeapTop(Heap *hp)
{
	return hp->array[0];
}

int Heapsize(Heap *hp)
{
	return hp->size;
}

/* HeapTop() 함수는 힙에서 우선 순위가 가장 높은 원소를 삭제하지 않고 반환합니다. */
/* Heapsize() 함수는 힙의 원소 수를 반환합니다. */