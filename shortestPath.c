#include "shortestPath.h"
#include <stdio.h>
#define INF 4096

void InitVertex(ALGraph * g, int src){
	int i=0;
	for(i=0;i<g->numV;i++){
		if(i!=src){
			g->vertexArr[i].d=INF;
		}else{
			g->vertexArr[i].d=0;
		}
	}
}
/*
void fillWeightMatrix(ALGraph * g){
	int i;
	Edge e;
	g->W = (int*)calloc(sizeof(int), (g->numV * g->numV));

	for(i=0;i<g->numE;i++){
		e = g->edgeArr[i];
		g->W[e.fromV * g->numV + e.toV] = e.weight;
	}
}
*/

int getWeight(ALGraph * g, int u, int v){
	return g->W[u * g->numV + v];
}

int Relax(ALGraph * g, int u, int v, int w){
	//int w = getEdgeWeight(g, v, u);
	if(g->vertexArr[v].d > g->vertexArr[u].d + w){
		g->vertexArr[v].d = g->vertexArr[u].d + w;
		g->vertexArr[v].pi = u;
		return 1;
	}
	return 0;
}

int Bellman_Ford(ALGraph * g, int src){
	int i=0;
	int j=0;

	InitVertex(g, src);

	for(i=1; i<g->numV; i++){
		for(j=0;j<g->numE;j++){
			Relax(g, g->edgeArr[j].fromV, g->edgeArr[j].toV, g->edgeArr[j].weight);
		}
	}

	for(j=0;j<g->numE;i++){
		if((g->vertexArr[g->edgeArr[i].fromV].d) > (g->vertexArr[g->edgeArr[i].toV].d + g->edgeArr[i].weight)){
			return 0;
		}
		else return 1;
	}

}

void PrintPredecessors(ALGraph * g, int src, int dest){
	if(src==dest){
		//printf("%s ", g->vertexArr[src].name);
		return;
	}

	else{
		PrintPredecessors(g, src, g->PI[src * g->numV + dest]);
	}
	printf("%s ", g->vertexArr[dest].name);
}

void PrintShortestPath(ALGraph * g, int src){
	int i;
		
	for(i=0;i < g->numV; i++){
		printf("To %s : %d  ", g->vertexArr[i].name, g->D[src * g->numV + i]);
		PrintPredecessors(g, src, i);
		printf("\n");
	}
}

void RetrieveDistancesFromSingleSource(ALGraph * g, int src){
	int i;
	for(i=0;i<g->numV;i++){
		g->D[src * g->numV + i] = g->vertexArr[i].d;
	}
	return;
}

void RetrievePredecessorsFromSingleSource(ALGraph * g, int src){
	//1. if predecessor of src itself: -1
	int i;
	for(i=0;i<g->numV;i++){
		if(i==src){
			g->PI[src * g->numV + i] = -1;
		}
		else{
			g->PI[src * g->numV + i] = g->vertexArr[i].pi;
		}
	}
	return;
}

void RunBellman_Ford(ALGraph * g){
	int i;
	for(i=0;i<g->numV;i++){
		Bellman_Ford(g, i);
		RetrieveDistancesFromSingleSource(g, i);
		RetrievePredecessorsFromSingleSource(g, i);
	}
}

void printDistanceMatrix(ALGraph *g){
	int i;
	int j;
	for(i=-1;i<g->numV;i++){
		for(j=-1;j<g->numV;j++){
			if(i<0 && j<0)
				printf("%9s", " ");
			else if(i<0)
				printf("%9s", g->vertexArr[j].name);
			else if(j<0)
				printf("%9s", g->vertexArr[i].name);
			else
				printf("%9d", g->D[i * g->numV + j]);
		}
		printf("\n");
	}
}



void Dijkstra(ALGraph * g, Heap * h, int src){
	//declare vars
	int i;
	int fromV;
	int toV;
	int w;

	//init vertices
	InitVertex(g, src);

	//add vertices into heap
	for(i=0;i<g->numV;i++){
		HInsert(h, i, g->vertexArr[i].d, &(g->vertexArr[i]));
	}

	//run while loop
	while(!HisEmpty(h)){
		//extract a vertex from heap
		fromV = HDelete(h);
		//relax for all adjacent vertices
		if(LFirst(&(g->adjList[fromV]), &toV)){
			//only when edge exist
			if(w=getWeight(g, fromV, toV)){
				if(Relax(g, fromV, toV, w)){
					//update corresponding heap element
					HPriorityDecrease(h, g->vertexArr[toV].handle, g->vertexArr[toV].d);
				}
			}
			while(LNext(&(g->adjList[fromV]), &toV)){
				if(w=getWeight(g, fromV, toV)){
					if(Relax(g, fromV, toV, w)){
						HPriorityDecrease(h, g->vertexArr[toV].handle, g->vertexArr[toV].d);
					}
				}
			}
		}
	}
}

void RunDijkstra(ALGraph * g, Heap * h){
	int i;
	for(i=0;i<g->numV;i++){
		Dijkstra(g, h, i);
		RetrieveDistancesFromSingleSource(g, i);
        RetrievePredecessorsFromSingleSource(g, i);
	}
}

	

			
