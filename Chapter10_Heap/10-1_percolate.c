/* 부모 노드 값을 자식 값 중 하나와 맞바꾸어 힙 특성을 재귀적으로 복원 */
void percolateDown(int *a, int position, int size, int isMinHeap)
{
	int lChild = 2 * position * 2 + 1;
	int rChild = lChild + 1;

	int small = -1;
	int temp;

	/* lChild 와 rChild 둘 중 더 작은 값(MinHeap의 경우)을 갖는 노드의 인덱스를 small에 저장 */
	if (lChild < size) {
		small = lChild;
	}

	if (rChild < size && comp(a[lChild], a[rChild], isMinHeap)) {
		small = rChild;
	}

	/* small = -1 인 상태이면 부모 노드가 가장 작은 값(MinHeap의 경우)이므로 최소힙을 만족 */
	/* small != -1 이면 부모 노드 보다 자식 노드에 더 작은 값이 있으므로 swap()을 수행 */
	if (small != -1 && comp(a[position], a[small], isMinHeap)) {
		temp = a[position];
		a[position] = a[small];
		a[small] = temp;
		percolateDown(a, small, size, isMinHeap);
	}
}

/* 자식 노드 값을 부모 노드와 맞바꾸어 힙 특성을 재귀적으로 복원 */
void percolateUp(int *a, int position, int isMinHeap)
{
	int parent = (position - 1) / 2;
	int temp;

	if (parent >= 0) {
		if (comp(a[parent], a[position], isMinHeap)) {
			temp = a[position];
			a[position] = a[parent];
			a[parent] = temp;
			percolateUp(a, parent, isMinHeap);
		}
	}
}