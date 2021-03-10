/* 그래프 순회 - DFS(Depth First Search, 깊이 우선 탐색)
 * 재귀(recursion)로 구현
 *
 * 1. DFS 함수에서 방문한 노드를 추적할 방문 배열을 생성
 * 2. DFS 함수에서 DFSRec 재귀 함수의 현재 노드 또는 인덱스 노드로 출발 노드를 전달
 * 3. 인덱스 노드에서 방문한 모든 노드를 재귀로 DFSRec 함수에 전달
 * 4. 출발 노드에서 모든 노드를 방문할 때 재귀를 끝내고 DFS 함수로 돌아감
 * 5. 마지막으로 방문 배열을 살펴보고 목적지 노드의 방문 여부를 확인 */


void DFSRec(Graph *gph, int index, int *visited)
{
	int destination;
	visited[index] = 1;
	GraphNode *head = gph->adj[index].next;
	while (head) {
		destination = head->dest;
		if (visited[destination] == 0) {
			DFSRec(gph, destination, visited);
		}
		head = head->next;
	}
}

int DFS(Graph *gph, int source, int target)
{
	int count = gph->count;
	int *visited = (int *)calloc(count, sizeof(int));
	DFSRec(gph, source, visited);
	return visited[target];
}
