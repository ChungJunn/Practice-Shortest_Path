Dijkstra와 Bellman-Ford알고리즘 구현은 성공했지만 Floyd-Warshall은 구현하지 못했습니다.

1. 실행 환경 : gcc

2. 실행 방법 : 
	$ gcc main.c shortestPath.c graph.c heap.c list.c
	$ ./a.out hw5.data
	
3. 실행 결과 :
	1) Dijkstra를 이용해서 걸리는 시간과 결과값 메트릭스 출력
	2) Bellman-Ford를 이용해서 걸리는 시간과 결과값 메트릭스 출력

4. negative edge가 포함될 경우 실행 결과:
	1) Dijkstra
	예상과 달리 잘 작동하는 것처럼 보인다. 책에서는 양수값의 edge만을 가정한다고 나와있다.
	하지만 negative edge가 포함되어도 Bellman-Ford와 같은 결과를 보인다.

	2) Bellman-Ford
	예상했던 대로 잘 작동한다.

5. negative cycle이 포함될 경우 실행결과:
	1) Dijkstra
	부정확한 값이 나온다.

	2) Bellman-Ford
	예상했던 대로 negative-cycle을 detect하고 함수의 반환값을 통해 이를 표시한다.