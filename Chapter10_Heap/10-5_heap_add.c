/* 힙 삽입 (isMinheap = 0 -> 최대힙)
1. 배열의 끝에 새 원소를 추가 -> 완전 이진 트리 구조는 유지하지만, 새 원소의 값이 부모의 값보다 클 수도 있어서 더이상 힙이 아닐 수 있음
2. 새 원소가 부모의 값보다 작을 때 까지 부모와 맞바꿈 -> percolateUp() 
3. 새 원소가 루트에 도달하거나 부모의 값이 새 원소보다 크거나 같으면 단계 2를 종료 */

typedef struct Heap
{
	int capacity;
	int size;
	int *array;
	int isMinHeap;
} Heap;

void HeapAdd(Heap *hp, int value)
{
	if (hp->size == hp->capacity)
		return ;
	hp->size++;
	hp->array[hp->size - 1] = value;
	percolateUp(hp->array, hp->size - 1, hp->isMinHeap);
}