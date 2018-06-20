#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

#include "list.h"
#include "graph.h"
#include "shortestPath.h"
#include "heap.h"

int main(int args, char ** argv){
	
	int i;
	ALGraph g;
	Edge e;
	Heap h;

	double elapsed_time=0.F;
	struct timeval t1, t2;

	int dim = GetMatrixDimFromFile(argv[1]);
	GraphInit(&g, dim);
	ReadGraphFromFile(&g, argv[1], dim);

	HeapInit(&h);

	if(args !=2) return;
	
	//1. Dijkstra
	gettimeofday(&t1, NULL);	
	RunDijkstra(&g, &h);
	gettimeofday(&t2, NULL);	
	
	elapsed_time = ((double)(t2.tv_usec / 1000000.F)+t2.tv_sec) - ((double)(t1.tv_usec / 1000000.)+t1.tv_sec);	

	printf("elapsed time(Dijkstra)\t = %15f sec. and shortest paths were computed as follows\n", elapsed_time);
	printDistanceMatrix(&g);

	printf("\n\n");

	//2. Bellman-Ford
	gettimeofday(&t1, NULL);	
	RunBellman_Ford(&g);
	gettimeofday(&t2, NULL);	
	
	elapsed_time = ((double)(t2.tv_usec / 1000000.F)+t2.tv_sec) - ((double)(t1.tv_usec / 1000000.)+t1.tv_sec);	

	printf("elapsed time(BellmanFord)\t = %15f sec. and shortest paths were computed as follows\n", elapsed_time);
	printDistanceMatrix(&g);

		
	return 0;
}
