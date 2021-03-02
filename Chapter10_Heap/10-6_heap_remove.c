/* 힙 삭제 (isMinheap = 0 -> 최대힙)
1. 힙의 루트 값을 반환 값 변수에 복사
2. 힘의 마지막 원소를 루트로 복사한 다음 힙 크기를 1만큼 줄임 -> out-of-place element
3. 제자리가 아닌 원소를 가장 큰 값의 자식과 바구어 힙 속성을 복원 
(제자리가 아닌 원소가 말단에 도달하거나 모든 자식보다 크거나 같을 때 까지 과정을 반복)
4. 1단계에서 저장한 값을 반환 */

typedef struct Heap
{
	int capacity;
	int size;
	int *array;
	int isMinHeap;
} Heap;

int HeapRemove(Heap *hp)
{
	int value = hp->array[0];
	hp->array[0] = hp->array[hp->size - 1];
	hp->size--;
	percolateDown(hp->array, 0, hp->size, hp->isMinHeap);
	return value;
}