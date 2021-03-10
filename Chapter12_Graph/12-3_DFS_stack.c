/* 그래프 순회 - DFS(Depth First Search, 깊이 우선 탐색)
 * stack 으로 구현
 * 트리의 DFS와 유사
 * 그래프에는 순환이 있기 때문에 같은 노드를 다시 방문하지 않도록 불 방문 배열(boolean visited array)을 사용
 *
 * 1. 스택에 시작 노드를 삽입
 * 2. 스택에서 노드를 꺼내 현재 노드 지정
 * 3. 현재 노드에서 출력 등의 작업을 수행
 * 4. 현재 노드의 모든 자식 노드를 순회해 스택에 넣는다.
 * 5. 스택이 빌 때까지 단계 2~4를 반복 */


int DFSStack(Graph *gph, int source, int target)
{
	int count = gph->count;
	int *visited = (int *)calloc(count, sizeof(int));
	int curr, destination;
	Stack stk;
	StackPush(&stk, source);
	visited[source] = 1;
	while (StackSize(&stk) != 0) {
		curr = StackPop(&stk);
		GraphNode *head = gph->adj[curr].next;
		while (head) {
			destination = head->dest;
			if (visited[destination] == 0) {
				StackPush(&stk, destination);
				visited[destination] = 1;
			}
			head = head->next;
		}
	}
	return visited[target];
}
