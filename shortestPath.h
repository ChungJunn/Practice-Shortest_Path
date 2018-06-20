#ifndef __graph_h__
#define __graph_h__
#include "graph.h"
#include "heap.h"

//1. Init Vertex
void InitVertex(ALGraph * g, int src);

//2 Relax
int Relax(ALGraph * g, int v, int u, int w);

//3. Bellman-Ford
int Bellman_Ford(ALGraph * g, int src);
void RunBellman_Ford(ALGraph * g);

//4. Dijkstra
void Dijkstra(ALGraph * g, Heap * h, int src);
void RunDijkstra(ALGraph * g, Heap *h);

//5. Floyd-Warsahll
void Floyd_Warshall(ALGraph * g, int * D, int *PI);

//6. printShortestPath
void PrintPredecessors(ALGraph * g, int src, int dest);

//7. PrintShortestPath
void PrintShortestPath(ALGraph * g, int src);

//8. retrieve result of single-source shortest paht
void RetrieveDistancesFromSingleSource(ALGraph * g, int src);
void RetrievePredecessorsFromSingleSource(ALGraph * g, int src);

//9. print matrix
void printMat(int * mat, int dim);

//int getWeight(ALGraph * g, int u, int v);

#endif
