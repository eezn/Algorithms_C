/* Adjacency Matrix : 인접 행렬
 * 그래프를 표현하는 방법
 * 구현이 쉽다
 * 정점 u 에서 정점 v 사이에 간선이 있는지 쿼리하는 데 O(1)
 * 간선을 제거하는 데 O(1)
 * 공간 복잡도 : O(n^2)
 * 간선의 수가 적은 희소 그래프라 해도 공간 복잡도가 동일하다.
 * 새로운 정점을 추가하는 데 O(n^2) */

typedef struct graph
{
	int count;
	int adj;
} Graph;

void graphInit(Graph *gph, int count)
{
	gph->count = count;
	gph->adj = (int**)malloc(sizeof(int*) * count);
	for (int i = 0; i < count; i++) {
		gph->adj[i] = (int*)malloc(sizeof(int) * count);
		memset(gph->adj[i], 0x0, sizeof(int) * count);
	}
}

void addDirectedEdge(Graph *gph, int src, int dst, int cost)
{
	gph->adj[src][dst] = cost;
}

void addUndirectedEdge(Graph *gph, int src, int dst, int cost)
{
	addDirectedEdge(gph, src, dst, cost);
	addDirectedEdge(gph, dst, src, cost);
}

void graphPrint(Graph *gph)
{
	int count = gph->count;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++)
			printf("%d ", gph->adj[i][j]);
		printf("\n");
	}
}


/* 값 입력 예시 */
int main()
{
	Graph graph;
	graphInit(&graph, 4); // vertax 개수 : 4
	addUndirectedEdge(&graph, 0, 1, 1);
	addUndirectedEdge(&graph, 0, 2, 1);
	addUndirectedEdge(&graph, 1, 2, 1);
	addUndirectedEdge(&graph, 2, 3, 1);
	graphPrint(&graph);
	return 0;
}
