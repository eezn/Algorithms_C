/* 부모 노드 값을 자식 값 중 하나와 맞바꾸어 힙 특성을 재귀적으로 복원 */
void percolateDown(int *a, int position, int size, int isMinHeap)
{
	int lChild = 2 * position * 2 + 1;
	int rChild = lChild + 1;

	int small = -1;
	int temp;

	if (lChild < size) {
		small = lChild;
	}

	if (rChild < size && comp(a[lChild], a[rChild], isMinHeap)) {
		small = rChild;
	}

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