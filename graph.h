#ifndef __ALGraph_h__
#define __ALGraph_h__
#include <stdlib.h>
#include "list.h"

#define MAX_VERTEX 128
#define MAX_EDGE 128
#define MAX_NAME 128

typedef int HandleToHeap;

typedef struct _vertex{
	char name[MAX_NAME];
	int d;
	int pi;
	HandleToHeap handle;
}Vertex;

typedef struct _edge{
	int fromV;
	int toV;
	int weight;
}Edge;

typedef struct _ALGraph{
	int numV;
	int numE;
	List * adjList;
	Edge edgeArr[MAX_EDGE];
	Vertex vertexArr[MAX_VERTEX];
	int edgeTop;
	//shortest Path
	int * D;
	int * PI;
	int * W; //weight matrix
}ALGraph;

int GetMatrixDimFromFile(char * fileName);

void ReadGraphFromFile(ALGraph * g, char * fileName, int numV);
 
void GraphInit(ALGraph * pg, int numV);

void GraphDestroy(ALGraph * pg);

void AddEdge(ALGraph * pg, Edge * edge);

void ShowGraphEdgeInfo(ALGraph * pg);

void fillWeightMatrix(ALGraph * g);

#endif
