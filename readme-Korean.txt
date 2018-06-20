Dijkstra�� Bellman-Ford�˰��� ������ ���������� Floyd-Warshall�� �������� ���߽��ϴ�.

1. ���� ȯ�� : gcc

2. ���� ��� : 
	$ gcc main.c shortestPath.c graph.c heap.c list.c
	$ ./a.out hw5.data
	
3. ���� ��� :
	1) Dijkstra�� �̿��ؼ� �ɸ��� �ð��� ����� ��Ʈ���� ���
	2) Bellman-Ford�� �̿��ؼ� �ɸ��� �ð��� ����� ��Ʈ���� ���

4. negative edge�� ���Ե� ��� ���� ���:
	1) Dijkstra
	����� �޸� �� �۵��ϴ� ��ó�� ���δ�. å������ ������� edge���� �����Ѵٰ� �����ִ�.
	������ negative edge�� ���ԵǾ Bellman-Ford�� ���� ����� ���δ�.

	2) Bellman-Ford
	�����ߴ� ��� �� �۵��Ѵ�.

5. negative cycle�� ���Ե� ��� ������:
	1) Dijkstra
	����Ȯ�� ���� ���´�.

	2) Bellman-Ford
	�����ߴ� ��� negative-cycle�� detect�ϰ� �Լ��� ��ȯ���� ���� �̸� ǥ���Ѵ�.