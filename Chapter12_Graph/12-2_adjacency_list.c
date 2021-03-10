/* Adjacency List : 인접 리스트
 * 공간을 효율적으로 사용
 * 연결 리스트의 배열 */


typedef struct graphNode
{
    int cost;
    int dest;
    struct graphNode *next;
} GraphNode;

typedef struct graph
{
    int count;
    GraphNode *adj;
} Graph;

void graphInit(Graph *gph, int count)
{
    gph->count = count;
    gph->adj = (GraphNode *)malloc(sizeof(GraphNode) * count);
    for (int i = 0; i < count; i++)
        gph->adj[i].next = NULL;
}

int addDirectedEdge(Graph *gph, int src, int dst, int cost)
{
    GraphNode *temp = (GraphNode *)malloc(sizeof(GraphNode));
    if (!temp) {
        printf("Memory Allocation Error");
        return 0;
    }
    temp->cost = cost;
    temp->dest = dst;
    temp->next = gph->adj[src].next;
    gph->adj[src].next = temp;
    return 1;
}

int addUndirectedEdge(Graph *gph, int src, int dst, int cost)
{
    return addDirectedEdge(gph, src, dst, cost) && addDirectedEdge(gph, dst, src, cost);
}

void printGraph(Graph *gph)
{
	GraphNode *head;
	if (!gph) {
		printf("그래프가 비었음");
		return;
	}
	printf("Graph count conut : %d \n", gph->count);
	for (int i = 0; i < gph->count; i++) {
		head = gph->adj[i].next;
		printf(" 노드 [ %d ]:", i);
		while (head) {
			printf("%d(%d) ", head->dest, head->cost);
			head = head->next;
		}
		printf("\n");
	}
}


/* 인접 리스트의 공간 복잡도는 정점 배열을 만들고 각 정점의 간선을 저장하므로 O(E + V)
 * 정점 u 에서 정점 v 까지 간선의 검색 시간 복잡도는 outdgree(u)를 수행하는 시간
 * 정점 u 의 이웃 리스트를 순회해야 하므로 최악의 경우 시간 복잡도는 O(E) */
