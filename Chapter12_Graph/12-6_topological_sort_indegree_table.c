/*
 * - indegree table 에서 indegree가 0인 요소부터 시작 (C, H) ← 의존성이 없는 vertax
 *
 * 1. C 에서 시작 (queue에 삽입)
 *    C 와 인접한 vertax D 의 indegree 에서 1을 빼준다 (D : 2 → 1)
 * 2. 그 다음 table에서 indegree가 0인 vertax를 찾으면 H (queue에 삽입)
 * 3. H와 인접한 D, I 의 indegree를 각 1씩 줄여 준다 (D: 1 → 0, I : 1 → 0)
 * 4. 그 다음 table에서 indegree가 0인 vertax 탐색 → D (queue에 삽입)
 *    D 와 인접한 A, E, F 의 indegree를 각 1씩 줄여 준다 (A : 1 → 0, E : 4 → 3, F : 2 → 1)
 * 5. 그 다음 table에서 indegree가 0인 vertax 탐색 → I (queue에 삽입)
 *    I 와 인접한 J 의 indegree를 1 줄여 줌 (J : 1 → 0)
 * 6. 그 다음 table에서 indegree가 0인 vertax 탐색 → A (queue에 삽입)
 *    A 와 인접한 B 의 indegree를 1 줄여 줌 (B : 1 → 0)
 * 7. 그 다음 table에서 indegree가 0인 vertax 탐색 → J (queue에 삽입)
 * 8. ... (반복)
 * 9. indegree table 의 indegree가 모두 0 이 되면 queue를 반환
 *
 * - Topological Sorting 은 Unique 하지 않은데,
 *   indegree가 0 인 vertax를 선택할 때 어떤 vertax 를 먼저 선택해서 수행하느냐에 따라 Sorting 결과가 조금씩 다를 수 있기 때문 */