/* heapify는 배열을 힙으로 변환하는 과정
1. 배열에 값이 존재
2. 배열의 중간에서 시작해서 인덱스 0 까지 반복, 각 단계에서 부모 값을 왼쪽 자식 및 오른쪽 자식과 비교
3. 배열의 중간에서 배열 시작까지의 모든 원소를 힙의 말단 노드에 도달할 때까지 비교해 옮김
시간복잡도는 O(n) */

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