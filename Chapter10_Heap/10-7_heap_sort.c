/* 힙 정렬 (in-place sort algorithm 은 최대힙으로만 가능)
1. 힙 생성 함수로 원소 목록으로 최대 힙을 만듭니다. -> O(n)
2. 힙에서 최댓값을 꺼내 이 값을 arr[size - 1] 위치인 배열의 끝 부분에 저장
	2-1. 힙 루트 값을 배열의 끝에 복사
	2-2. 힙의 마지막 원소를 루트로 복사하고 힙의 크기를 1만큼 줄임
	2-3. percolataDown() -> 힙 속성 복원
3. 힙에 원소가 하나만 남을 때 까지 과정 반복 */

typedef struct Heap
{
	int capacity;
	int size;
	int *array;
	int isMinHeap;
} Heap;

void HeapSort(int arr[], int size, int inc)
{
	Heap hp;
	int *b = (int *)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		b[i] = arr[i];
	}
	HeapInitialize(&hp, b, size, inc);
	for (int i = 0; i < size; i++)
		arr[i] = HeapRemove(&hp);
}

/* 
 * 최악 성능 시간 복잡도 : O(nlogn)
 * 최선 성능 시간 복잡도 : O(nlogn)
 * 평균 시간 복잡도 : O(nlogn)
 * 공간 복잡도 : O(1)
 * 힙 정렬은 안정 정렬이 아니며 배열을 정렬하는 데 추가 공간을 요구하지 않음
 * 
 * 안정 정렬 :  
*/