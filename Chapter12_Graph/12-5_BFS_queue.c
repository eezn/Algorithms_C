/* 그래프 순회 - BFS(Breadth First Search, 너비 우선 탐색)
 * queue 로 구현
 *
 * 그래프를 레이어별로 순회 : 시작점에서 더 가까운 곳을 순회
 *
 * 1. 큐에 시작 노드를 삽입
 * 2. 반복문 내에서 큐의 노드를 꺼내 현재 노드로 설정
 * 3. 현재 노드에서 출력 등의 작업을 수행
 * 4. 현재 노드의 모든 자식 노드를 순회해 큐에 삽입
 * 5. 큐가 빌 때까지 단계 2~4를 반복 */


int BFS(Graph *gph, int source, int target)
{
	int count = gph->count;
	int *visited = (int *)calloc(count, sizeof(int));
	visited[source] = 1;
	int curr, destination;
	Queue que;
	QueueInitialize(&que);
	QueueAdd(&que, source);
	while (QueueSize(&que) != 0) {
		curr = QueueRemove(&que);
		GrapeNode *head = gph->adj[curr].next;
		while (head) {
			destination = head->dest;
			if (visited[destination] == 0) {
				QueueAdd(&que, destination);
				visited[destination] = 1;
			}
			head = head->next;
		}
	}
	return visited[target];
}
