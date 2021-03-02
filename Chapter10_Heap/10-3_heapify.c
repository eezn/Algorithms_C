typedef struct Heap
{
	int capacity;
	int size;
	int *array;
	int isMinHeap;
} Heap;

void HeapInitialize(Heap *hp, int arr[], int size, int isMinHeap)
{
	hp->size = hp->capacity = size;
	hp->array = arr;
	hp->isMinHeap = isMinHeap;
	heapify(arr, size, isMinHeap);
}

void heapify(int arr[], int size, int isMinHeap)
{
	/* (size) / 2 : 힙의 중간부터 시작해서 루트 노드까지 */
	for (int i = (size) / 2; i >= 0; i--)
		percolateDown(arr, i, size, isMinHeap);
}

/* 10-4_heapinitialize2 : 어디다 쓰는거지? */
void HeapInitialize2(Heap *hp, int size, int isMinHeap)
{
	hp->size = 0;
	hp->capacity = size;
	hp->isMinHeap = isMinHeap;
	hp->array = (int *)malloc((size + 1) * sizeof(int));
}